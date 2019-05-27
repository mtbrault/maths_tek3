/*
** EPITECH PROJECT, 2018
** 301dannon
** File description:
** operation class
*/

#ifndef OPERATION_HPP_
# define OPERATION_HPP_

#include <vector>

class Operation {
public:
	Operation(std::string);
	~Operation();
	int	run();

private:
	void	selectSort();
	void	insertionSort();
	void	bubbleSort();
	void	fusionSort();
	void	quickSort();
	void	fillList(std::string);

	std::vector<double>	_list;
	std::string	_filename;
};

#endif /* !OPERATION_HPP_ */
