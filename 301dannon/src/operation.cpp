/*
** EPITECH PROJECT, 2018
** 301dannon
** File description:
** operation method
*/

#include <fstream>
#include <iostream>
#include "operation.hpp"

Operation::Operation(std::string filename)
	: _filename(filename)
{
}

Operation::~Operation()
{
}

void	Operation::fillList(std::string line)
{
	std::string	val;
	auto start = 0;
	auto end = line.find(' ');
	while ("Yaniss Pheron is an handsom man") {
		val = line.substr(start, end - start);
		try {
			_list.push_back(std::stod(val));
		} catch (std::exception &ex) {
		}
		if (end == std::string::npos)
			break ;
		start = end + 1;
		end = line.find(' ', start);
	}
}

int	Operation::run()
{
	std::ifstream	content(_filename);
	std::string		line;

	if (!content)
		throw std::overflow_error("The file doesn't exist");
	getline(content, line);
	this->fillList(line);
	if (_list.size() <= 0)
		throw std::overflow_error("Empty or incorrect file");
	std::cout << _list.size() << ((_list.size() <= 1) ? " element" : " elements") << std::endl;
	selectSort();
	insertionSort();	
	bubbleSort();
	fusionSort();
	quickSort();
	return 0;
}

void	Operation::selectSort()
{
	std::vector<double>	tmp = _list;
	int					min;
	int					nbComp = 0;
	double				stock;

	for (int j = 0; j < (int)((tmp.size() - 1)); j++) {
		min = j;
		for (int i = j + 1; i < (int)tmp.size(); i++) {
			if (tmp[i] < tmp[min])
				min = i;
			nbComp++;
		}
		if (min != j) {
			stock = tmp[min];
			tmp[min] = tmp[j];
			tmp[j] = stock;	
		}
	}
	std::cout << "select sort: " << nbComp << ((nbComp <= 1) ? " comparison" : " comparisons") << std::endl;
}

void	Operation::bubbleSort()
{
	std::vector<double>	tmp = _list;
	int			nbComp = 0;
	double		stock;

	for (int i = (int)tmp.size() - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			nbComp++;
			if (tmp[j + 1] < tmp[j]) {
				stock = tmp[j + 1];
				tmp[j + 1] = tmp[j];
				tmp[j] = stock;
			}
		}
	}
	std::cout << "bubble sort: " << nbComp << ((nbComp <= 1) ? " comparison" : " comparisons") << std::endl;
}

void	Operation::insertionSort()
{
	std::vector<double>	tmp = _list;
	std::vector<double> sort;
	int					size;
	int					nbComp = 0;

	sort.push_back(tmp[0]);
	tmp.erase(tmp.begin());
	while (tmp.size() != 0) {
		size = (int)sort.size();
		for (int i = 0; i < size; i++) {
			nbComp++;
			if (sort[i] > tmp[0]) {
				sort.insert(sort.begin() + i, tmp[0]);
				tmp.erase(tmp.begin());
				break ;
			}
			else if ((i + 1) >= (int)sort.size()) {
				sort.push_back(tmp[0]);
				tmp.erase(tmp.begin());
			}
		}
	}
	std::cout << "insertion sort: " << nbComp << ((nbComp <= 1) ? " comparison" : " comparisons") << std::endl;
}

static int	algoQuick(std::vector<double> &tmp)
{
	std::vector<double>	first;
	std::vector<double> second;
	int					nbComp = 0;

	for (int i = 1; i < (int)tmp.size(); i++) {
		if (tmp[i] < tmp[0])
			first.push_back(tmp[i]);
		else
			second.push_back(tmp[i]);
		nbComp++;
	}
	if (tmp.size() <= 1)
		return 0;
	return nbComp + algoQuick(first) + algoQuick(second);
}
 
void	Operation::quickSort()
{
	int	nbComp = algoQuick(_list);

	std::cout << "quicksort: " << nbComp << ((nbComp <= 1) ? " comparison" : " comparisons") << std::endl;
}

static int	algoFusion(std::vector<double> &list)
{
	int					nbComp;
	std::vector<double>	list1;
	std::vector<double>	list2;
	std::vector<double> finalList;
	int					middle = (list.size() % 2 == 0) ? list.size() / 2 : list.size() / 2;

	if (list.size() == 1)
		return 0;
	for (int i = 0; i < (int)list.size(); i++) {
		if (i < middle)
			list1.push_back(list[i]);
		else
			list2.push_back(list[i]);
	}
	nbComp = algoFusion(list1) + algoFusion(list2);
	while (list1.size() != 0 || list2.size() != 0) {
		if (list1.size() == 0) {
			finalList.push_back(list2[0]);
			list2.erase(list2.begin());
		} else if (list2.size() == 0) {
			finalList.push_back(list1[0]);
			list1.erase(list1.begin());
		} else {
			if (list1[0] < list2[0]) {
				finalList.push_back(list1[0]);
				list1.erase(list1.begin());
			} else {
				finalList.push_back(list2[0]);
				list2.erase(list2.begin());
			}
			nbComp++;
		}
	}
	list = finalList;
	return nbComp;
}

void	Operation::fusionSort()
{
	std::vector<double>	tmp = _list;
	int					nbComp = algoFusion(tmp);

	std::cout << "fusion sort: " << nbComp << ((nbComp <= 1) ? " comparison" : " comparisons") << std::endl;
}
