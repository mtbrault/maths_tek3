/*
** EPITECH PROJECT, 2018
** 306radiator
** File description:
** radiator method
*/

#include "Radiator.hpp"

Radiator::Radiator(int size, int b, int c)
	: _size(size), _b(b), _c(c), _d(-1), _e(-1)
{
	if (size < 2 || b < 1 || c < 1 || b > size - 2 || c > size - 2)
		throw std::overflow_error("Error");
}

Radiator::Radiator(int size, int b, int c, int d, int e)
	: _size(size), _b(b), _c(c), _d(d), _e(e)
{
	if (size < 2 || b < 1 || c < 1 || b > size - 2 || c > size - 2)
		throw std::overflow_error("Error");
	else if (d < 1 || e < 1 || d > size - 2 || e > size - 2)
		throw std::overflow_error("Error");
}

Radiator::~Radiator()
{
}

void	Radiator::initMap()
{
	std::vector<int>	tmp;

	for (int i = 0; i < (_size * _size); i++)
		tmp.push_back(0);
	for (int i = 0; i < (_size * _size); i++)
		_map.push_back(tmp);
}

void	Radiator::displayMap()
{
	unsigned int tmp;

	for (auto &it : _map) {
		tmp = 0;
		for (auto &i : it) {
			std::cout << i;
			if (tmp < it.size() - 1)
				std::cout << "\t";
			tmp++;
		}
		std::cout << std::endl;
	}
}

void	Radiator::run()
{
	initMap();
	displayMap();
	(void)_b;(void)_c;(void)_d;(void)_e;
}