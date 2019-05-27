/*
** EPITECH PROJECT, 2019
** 309poulltion
** File description:
** Pollution class
*/

#ifndef POLLUTION_HPP_
	#define POLLUTION_HPP_

#include <vector>
#include <iostream>

class Pollution {
public:
	Pollution(int, const std::string &, float, float);
	~Pollution();

	void	run();
	void	parsFile(const std::string &);

private:
	int			_nbPoint;
	float		_x;
	float		_y;
};

#endif /* !POLLUTION_HPP_ */
