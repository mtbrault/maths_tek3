/*
** EPITECH PROJECT, 2018
** 305construction
** File description:
** main file
*/

#include "Construction.hpp"

static int	myError(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return myError("Invalid nb args");
	Construction	construction(av[1]);
	try {
		construction.run();
	} catch (std::overflow_error &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}