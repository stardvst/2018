#include <iostream>
#include <cmath>
#include <ctime>
#include "City.h"
#include "Cities.h"
#include "Tour.h"

double acceptanceProbability(const double energy, const double newEnergy, const double temperature)
{
	if (newEnergy < energy)
		return 1;
	return std::exp((static_cast<double>(energy) - static_cast<double>(newEnergy)) / temperature);
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	const City city1(60, 200);
	Cities::addCity(city1);
	const City city2(180, 200);
	Cities::addCity(city2);
	const City city3(80, 180);
	Cities::addCity(city3);
	const City city4(140, 180);
	Cities::addCity(city4);
	const City city5(20, 160);
	Cities::addCity(city5);
	const City city6(100, 160);
	Cities::addCity(city6);
	const City city7(200, 160);
	Cities::addCity(city7);
	const City city8(140, 140);
	Cities::addCity(city8);
	const City city9(40, 120);
	Cities::addCity(city9);
	const City city10(100, 120);
	Cities::addCity(city10);
	const City city11(180, 100);
	Cities::addCity(city11);
	const City city12(60, 80);
	Cities::addCity(city12);
	const City city13(120, 80);
	Cities::addCity(city13);
	const City city14(180, 60);
	Cities::addCity(city14);
	const City city15(20, 40);
	Cities::addCity(city15);
	const City city16(100, 40);
	Cities::addCity(city16);
	const City city17(200, 40);
	Cities::addCity(city17);
	const City city18(20, 20);
	Cities::addCity(city18);
	const City city19(60, 20);
	Cities::addCity(city19);
	const City city20(160, 20);
	Cities::addCity(city20);

	double temperature = 10000;
	const auto coolingRate = 0.003;

	Tour currentSolution;
	currentSolution.generateIndividual();

	std::cout << "Initial solution distance: " << currentSolution.getDistance() << '\n';

	// current best
	Tour best(currentSolution);

	while (temperature > 1)
	{
		Tour newSolution = currentSolution;

		// random position in tour
		const auto pos1 = std::rand() % newSolution.tourSize();
		const auto pos2 = std::rand() % newSolution.tourSize();

		// cities to swap
		const auto cityToSwap1 = newSolution.getCity(pos1);
		const auto cityToSwap2 = newSolution.getCity(pos2);

		// swap!
		newSolution.setCity(pos1, cityToSwap2);
		newSolution.setCity(pos2, cityToSwap1);

		// energies of solutions
		const auto currentEnergy = currentSolution.getDistance();
		const auto neighborEnergy = newSolution.getDistance();

		// accept the neighbor?
		if (acceptanceProbability(currentEnergy, neighborEnergy, temperature) > std::rand() % 1)
			currentSolution = newSolution;

		// is it the best so far?
		if (currentSolution.getDistance() < best.getDistance())
			best = currentSolution;

		temperature *= 1 - coolingRate;
	}
	
	std::cout << "Final solution distance: " << best.getDistance() << '\n';
	std::cout << "Tour: " << best << '\n';

	std::cin.get();
}
