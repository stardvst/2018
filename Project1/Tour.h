#pragma once

#include <ostream>
#include <vector>
#include <algorithm>
#include <random>
#include "City.h"
#include "Cities.h"

class Tour
{
public:
	Tour();
	Tour(const Tour& tour);
	
	const City& getCity(int index) const;
	void setCity(int index, const City& city);

	const std::vector<City> &getTour() const { return m_vecTour; }
	int tourSize() const;
	double getDistance() const;

	void generateIndividual();

private:
	std::vector<City> m_vecTour{};
	mutable double m_nDistance = 0;
};

inline Tour::Tour()
{
	for (auto idx = 0; idx < Cities::numberOfCities(); ++idx)
		m_vecTour.emplace_back();
}

inline Tour::Tour(const Tour& tour): m_vecTour(tour.m_vecTour), m_nDistance(tour.m_nDistance)
{
}

inline const City& Tour::getCity(const int index) const
{
	return m_vecTour.at(index);
}

inline void Tour::setCity(const int index, const City& city)
{
	m_vecTour.at(index) = city;
	m_nDistance = 0;
}

inline int Tour::tourSize() const
{
	return m_vecTour.size();
}

inline double Tour::getDistance() const
{
	if (m_nDistance == 0)
	{
		double tourDistance = 0;
		for (auto idx = 0; idx < tourSize(); ++idx)
		{
			auto fromCity = getCity(idx);
			auto destinationCity = idx + 1 < tourSize() ? getCity(idx + 1) : getCity(0);
			tourDistance += fromCity.distanceTo(destinationCity);
		}
		m_nDistance = tourDistance;
	}
	return m_nDistance;
}

inline void Tour::generateIndividual()
{
	for (auto idx = 0; idx < Cities::numberOfCities(); ++idx)
		setCity(idx, Cities::getCity(idx));
	
	// shuffle
	std::random_device r;
	std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() }; // 2
	std::mt19937 gen(seed);
	std::shuffle(m_vecTour.begin(), m_vecTour.end(), gen);
}

inline std::ostream &operator<<(std::ostream &os, const Tour &tour)
{
	std::string route("|");
	for (auto idx = 0; idx < tour.tourSize(); ++idx)
		route += tour.getCity(idx).toStr() + "|";
	return os << route;
}
