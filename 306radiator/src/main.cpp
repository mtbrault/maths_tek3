/*
** EPITECH PROJECT, 2018
** 306radiator
** File description:
** main file
*/

#include "Radiator.hpp"

static int	printError(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

int	main(int ac, char **av)
{
	if (ac != 4 && ac != 6)
		return printError("Invalid nb args");
	else if (ac == 4) {
		try {
			Radiator radiator(std::stoi(av[1]), std::stoi(av[2]), std::stoi(av[3]));
			radiator.run();
		} catch (std::overflow_error &ex) {
			std::cerr << ex.what() << std::endl;
			return 84;
		}
	}
	else {
		try {
			Radiator radiator(std::stoi(av[1]), std::stoi(av[2]), std::stoi(av[3]), std::stoi(av[4]), std::stoi(av[5]));
			radiator.run();
		} catch (std::overflow_error &ex) {
			std::cerr << ex.what() << std::endl;
			return 84;
		}
	}
	return 0;
}