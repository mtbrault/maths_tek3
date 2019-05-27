/*
** EPITECH PROJECT, 2019
** 308reedpipes
** File description:
** Reedpipes class
*/

#ifndef REEDPIPES_HPP_
	#define REEDPIPES_HPP_

#include <array>
#include <iostream>

class Reedpipes {
public:
	Reedpipes(double, double, double, double, double, int);
	~Reedpipes();

	void	run();
	void	newton();
	void	calcVector();
	double	polynome(double);

private:
	double	_r0;
	double	_r5;
	double	_r10;
	double	_r15;
	double	_r20;
	int		_nbPoint;
	double	_coef1;
	double	_coef2;
	double	_coef3;
	double	_coef4;

	std::array<double, 5>	_vector;
};

#endif /* !REEDPIPES_HPP_ */
