/*
** EPITECH PROJECT, 2018
** 302separation
** File description:
** main file
*/

#include "separation.hpp"

static int	printError(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 84;
}

static int	execAction(int ac, char **av)
{
	try {
		Separation	Separation(av, (ac == 3) ? 1 : 2);

		if (ac == 3)
			Separation.resultMatrice();
		else
			Separation.simpleConnect();
	} catch (std::overflow_error &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
	return 0;
}

int	main(int ac, char **av)
{
	if (ac == 3 || ac == 4)
		return execAction(ac, av);
	else
		return printError("Bad number of parameters");
}