/*
** EPITECH PROJECT, 2018
** 306radiator
** File description:
** Radiator class
*/

#ifndef RADIATOR_HPP_
	#define RADIATOR_HPP_

#include <iostream>
#include <vector>

class Radiator {
public:
	Radiator(int, int, int);
	Radiator(int, int, int, int, int);
	~Radiator();

	void	run();

private:
	void	initMap();
	void	displayMap();
	int	_size;
	int	_b;
	int	_c;
	int	_d;
	int	_e;
	std::vector<std::vector<int> >	_map;
};

#endif /* !RADIATOR_HPP_ */
