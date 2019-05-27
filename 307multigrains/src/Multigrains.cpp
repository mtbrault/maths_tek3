/*
** EPITECH PROJECT, 2018
** 307multigrains
** File description:
** Multigrains method
*/

#include "Multigrains.hpp"

Multigrains::Multigrains(char **av)
{
	_f1 = std::stoi(av[1]);
	_f2 = std::stoi(av[2]);
	_f3 = std::stoi(av[3]);
	_f4 = std::stoi(av[4]);
	_oatmeal = std::stoi(av[5]);
	_wheat = std::stoi(av[6]);
	_corn = std::stoi(av[7]);
	_barley = std::stoi(av[8]);
	_soy = std::stoi(av[9]);
	for (int i = 1; av[i]; i++) {
		if (std::stoi(av[i]) < 0 || (std::stoi(av[i]) == 0 && i >= 5))
			throw std::overflow_error("Negative value impossible");
	}
	_needs["oatmeal"] = {1, 1, 2, 0};
	_needs["wheat"] = {0, 2, 1, 0};
	_needs["corn"] = {1, 0, 0, 3};
	_needs["barley"] = {0, 1, 1, 1};
	_needs["soy"] = {2, 0, 0, 2};
}

Multigrains::~Multigrains()
{
}

void	Multigrains::display(const std::string &name, float val, int price)
{
	std::cout << name << ": " << val << " units at € " << price << " /unit" << std::endl;
}

void	Multigrains::run()
{
	algo();
	std::cout << "resources: " << _f1 << " F1, " << _f2 << " F2, " << _f3 << " F3, " << _f4 << " F4" << std::endl << std::endl;
	display("oatmeal", 0, _oatmeal);
	display("wheat", 0, _wheat);
	display("corn", 0, _corn);
	display("barley", 0, _barley);
	display("soy", 0, _soy);
	std::cout << "total production value: € " << 0 << std::endl;
}

void	Multigrains::algo()
{
}