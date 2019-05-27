/*
** EPITECH PROJECT, 2018
** 301dannon
** File description:
** main file
*/

#include <fstream>
#include <iostream>
#include "operation.hpp"

static int print_error(std::string msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

static int print_help(void)
{
	std::ifstream	file("help.txt");
	std::string		line;

	if (file) {
		while (getline(file, line))
			std::cout << line << std::endl;
	}
	return 0;
}

int	main(int ac, char **av)
{
	std::string	filename;

	if (ac != 2)
		return print_error("Bad number of parameters");
	filename = av[1];
	if (filename == "-h")
		return print_help();
	Operation	operation(filename);
	try {
		operation.run();
	} catch (std::overflow_error &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}