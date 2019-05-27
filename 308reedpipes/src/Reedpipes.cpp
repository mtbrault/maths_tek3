/*
** EPITECH PROJECT, 2019
** 308reedpipes
** File description:
** Reedpipes method
*/

#include <iomanip>
#include "Reedpipes.hpp"

Reedpipes::Reedpipes(double r0, double r5, double r10, double r15, double r20, int nb)
	: _r0(r0), _r5(r5), _r10(r10), _r15(r15), _r20(r20), _nbPoint(nb)
{
	if (nb <= 0 || _r5 <= 0 || _r10 <= 0 || _r15 <= 0 || _r20 <= 0)
		throw std::overflow_error("n can't be equal to 0");
}

Reedpipes::~Reedpipes()
{
}

void	Reedpipes::calcVector()
{
	std::array<double, 4>	cof;
	std::array<double, 5>	dev;
	std::array<std::array<double, 5>, 5>	inv;
	double					tmp;
	
	cof = {
		(_r5 - _r0) / 5,
		(_r10 - _r5) / 5,
		(_r15 - _r10) / 5,
		(_r20 - _r15) / 5
	};

	dev = {
		0,
		(cof[1] - cof[0]) / 10 * 6,
		(cof[2] - cof[1]) / 10 * 6,
		(cof[3] - cof[2]) / 10 * 6,
		0
	};

	inv[0] = {1.0, 0.0, 0.0, 0.0, 0.0};
	inv[1] = {-15.0 / 56.0, 15.0/28.0, -1.0 / 7.0, 1.0 / 28.0, -1.0 / 56.0};
	inv[2] = {1.0 / 14.0, -1.0 / 7.0, 4.0/7.0, -1.0/7.0, 1.0/14.0};
	inv[3] = {-1.0/56.0, 1.0/28.0, -1.0/7.0, 15.0/28.0, -15.0/56.0};
	inv[4] = {0, 0, 0, 0, 1};

	for (double i = 0; i < 5; i++) {
		tmp = 0;
		for (double j = 0; j < 5; j++)
			tmp += inv[i][j] * dev[j];
		if (tmp < 0 && tmp > -0.05)
			tmp = 0;
		_vector[i] = tmp;
	}
}

void	Reedpipes::newton()
{
	std::array<double, 5>	l1 = {0, 5, 10, 15, 20};
	std::array<double, 4>	l3;
	std::array<double, 3>	l4;
	std::array<double, 2>	l5;
	double					result;

	l3[0] = (_r5 - _r0) / (l1[1] - l1[0]);
	l3[1] = (_r10 - _r5) / (l1[2] - l1[1]);
	l3[2] = (_r15 - _r10) / (l1[3] - l1[2]);
	l3[3] = (_r20 - _r15) / (l1[4] - l1[3]);
	l4[0] = (l3[1] - l3[0]) / (l1[2] - l1[0]);
	l4[1] = (l3[2] - l3[1]) / (l1[3] - l1[1]);
	l4[2] = (l3[3] - l3[2]) / (l1[4] - l1[2]);
	l5[0] = (l4[1] - l4[0]) / (l1[3] - l1[0]);
	l5[1] = (l4[2] - l4[1]) / (l1[4] - l1[1]);
	result = (l5[1] - l5[0]) / (l1[4] - l1[0]);
	_coef1 = l3[0];
	_coef2 = l4[0];
	_coef3 = l5[0];
	_coef4 = result;
}

double	Reedpipes::polynome(double x)
{
	double	result;

	result = _r0 + _coef1 * (x - 1) + _coef2 * (x - 1) * (x - 2) + _coef3 * (x - 1) * (x - 2) * (x - 3) + _coef4 * (x - 1) * (x - 2) * (x - 3) * (x - 4);
	return result;
}

void	Reedpipes::run()
{
	double	interv = 20 / (double)(_nbPoint - 1);
	double	tmp = 0;

	calcVector();
	newton();
	std::cout << std::fixed << std::setprecision(1) <<  "vector result: [" << _vector[0] << ", " << _vector[1] << ", " << _vector[2] << ", " << _vector[3] << ", " << _vector[4] << "]" << std::endl;
	for (int i = 0; i < _nbPoint; i++) {
		std::cout << std::fixed << std::setprecision(1) << "abscissa: " << tmp;
		std::cout << " cm\tradius: " << polynome(tmp) << " cm" << std::endl;
		tmp += interv;
	}
}