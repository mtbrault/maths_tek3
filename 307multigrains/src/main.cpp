/*
** EPITECH PROJECT, 2018
** 307multigrains
** File description:
** main file
*/

#include <iostream>
#include "Multigrains.hpp"

static int	printError(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

int	main(int ac, char **av)
{
	if (ac != 10)
		return printError("Invalid nb args");
	try {
		Multigrains	multi(av);
		multi.run();
	} catch (const std::exception &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}