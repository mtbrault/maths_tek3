/*
** EPITECH PROJECT, 2018
** 304pacman
** File description:
** main file
*/

#include "Pacman.hpp"

static int		writeError(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

static int		myStrlen(char *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i++);
	return i;
}

int		main(int ac, char **av)
{
	if (ac != 4)
		return writeError("Invalid nb args");
	else if (myStrlen(av[2]) != 1 || myStrlen(av[3]) != 1 || av[2][0] == av[3][0])
		return writeError("Invalie char given");
	Pacman	pacman(av[1], av[2][0], av[3][0]);
	try {
		pacman.run();
	} catch (std::overflow_error &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}