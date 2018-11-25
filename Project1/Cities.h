#pragma once

#include <vector>
#include "City.h"

class Cities
{
public:
	static void addCity(const City &city)
	{
		m_vecCities.push_back(city);
	}

	static const City &getCity(const int index)
	{
		return m_vecCities.at(index);
	}

	static int numberOfCities()
	{
		return m_vecCities.size();
	}

private:
	inline static std::vector<City> m_vecCities{};
};