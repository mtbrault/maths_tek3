/*
** EPITECH PROJECT, 2019
** 309pollution
** File description:
** main file
*/

#include "Pollution.hpp"

static int	printError(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

int	main(int ac, char **av)
{
	if (ac != 5)
		return printError("Invalid nb args");
	try {
		Pollution	pollution(std::stoi(av[1]), av[2], std::stof(av[3]), std::stof(av[4]));
		pollution.run();
	} catch (const std::exception &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}