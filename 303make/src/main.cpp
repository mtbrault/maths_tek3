/*
** EPITECH PROJECT, 2018
** 303make
** File description:
** main file
*/

#include "Make.hpp"

static int print_err(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

int main(int ac, char **av)
{
	Make	operation;

	if (ac == 2)
		operation.setMakefile(av[1]);
	else if (ac == 3) {
		operation.setMakefile(av[1]);
		operation.setModified(av[2]);
	}
	else
		return print_err("Invalid nb args");
	try {
		operation.run();
	} catch (std::overflow_error &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}