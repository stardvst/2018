#pragma once

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <ostream>
#include <string>

class City
{
public:
	City()
	{
		srand(static_cast<unsigned>(time(nullptr)));
		m_x = std::rand() % 200;
		m_y = std::rand() % 200;
	}

	City(const int aX, const int aY) : m_x(aX), m_y(aY) {}

	// getters
	int getX() const { return m_x; }
	int getY() const { return m_y; }

	// distance to
	double distanceTo(const City &city) const
	{
		const auto cityX = std::abs(getX() - city.getX());
		const auto cityY = std::abs(getY() - city.getY());
		return std::sqrt(cityX * cityX + cityY * cityY);
	}

	std::string toStr() const
	{
		return  std::to_string(m_x) + ", " + std::to_string(m_y);
	}

private:
	int m_x{};
	int m_y{};
};

inline std::ostream &operator<<(std::ostream &os, const City &city)
{
	os << city.getX() << ", " << city.getY();
	return os;
}