/*
** EPITECH PROJECT, 2019
** reedpipes
** File description:
** main file
*/

#include "Reedpipes.hpp"

static bool	isNumber(char *nb, bool decim)
{
	for (int i = 0; nb[i] != '\0'; i++) {
		if (nb[i] < '0' || nb[i] > '9') {
			if (!decim || (decim && nb[i] != '.'))
				return false;
		}
	}
	return true;
}

static int	printError(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

int	main(int ac, char **av)
{
	if (ac != 7)
		return printError("Invalid nb args");
	for (int i = 1; i < 6; i++) {
		if (!isNumber(av[i], true))
			return printError("Arguments must be number");
	}
	if (!isNumber(av[6], false))
		return printError("Nb points must be interger");
	try {
		Reedpipes project(std::stod(av[1]), std::stod(av[2]), std::stod(av[3]), std::stod(av[4]), std::stod(av[5]), std::stoi(av[6]));
		project.run();
	} catch (const std::exception &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
}