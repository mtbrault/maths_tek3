/*
** EPITECH PROJECT, 2019
** 309pollution
** File description:
** Pollution method
*/

#include <fstream>
#include "Pollution.hpp"

Pollution::Pollution(int nbPoint, const std::string &file, float x, float y)
	: _nbPoint(nbPoint), _x(x), _y(y)
{
	if (nbPoint <= 0)
		throw std::overflow_error("Invalid nb point");
	if (x < 0 || x > nbPoint || y < 0 || y > nbPoint)
		throw std::overflow_error("Bad param");
	this->parsFile(file);
}

Pollution::~Pollution()
{
}

static std::vector<std::string>	parsLine(std::string line)
{
	std::vector<std::string>	val;
	auto						start = 0;
	auto						end = line.find(' ');
	while ("Infinite loop") {
		val.push_back(line.substr(start, end - start));
		if (end == std::string::npos)
			break ;
		start = end + 1;
		end = line.find(' ', start);
	}
	return val;
}

void	Pollution::parsFile(const std::string &file)
{
	std::ifstream				content(file);
	std::string					line;
	std::vector<std::string>	parsedLine;

	if (!content)
		throw std::overflow_error("Invalid file");
	while (getline(content, line)) {
		if (line.size() == 0)
			continue ;
		parsedLine = parsLine(line);
	}
}

void	Pollution::run()
{
	(void)_nbPoint; (void)_x;(void)_y;
}