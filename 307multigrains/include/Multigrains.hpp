/*
** EPITECH PROJECT, 2018
** 307multigrains
** File description:
** Multigrains class
*/

#ifndef MULTIGRAINS_HPP_
	#define MULTIGRAINS_HPP_

#include <iostream>
#include <array>
#include <unordered_map>

class Multigrains {
public:
	Multigrains(char **);
	~Multigrains();

	void	run();
	void	display(const std::string &, float, int);
	void	algo();

private:
	int	_f1;
	int	_f2;
	int	_f3;
	int	_f4;
	int	_oatmeal;
	int	_wheat;
	int	_corn;
	int	_barley;
	int	_soy;
	int	_product;
	std::unordered_map<std::string, std::array<int, 4> >	_needs;
};

#endif /* !MULTIGRAINS_HPP_ */
