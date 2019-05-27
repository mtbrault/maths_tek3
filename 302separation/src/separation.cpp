/*
** EPITECH PROJECT, 2018
** 302separation
** File description:
** separation method
*/

#include <fstream>
#include "separation.hpp"

static bool	existName(std::vector<std::string> list, std::string name)
{
	for (auto &it : list) {
		if (it == name)
			return true;
	}
	return false;
}

Separation::Separation(char **av, int opt)
{
	std::ifstream	content(av[1]);
	std::string		line;
	std::string		friend1;
	std::string		friend2;
	std::string		pars = " is friends with ";
	size_t			index;
	std::map<std::string, int>		tmp;

	if (!content)
		throw std::overflow_error("The file dosen't exist");
	while (getline(content, line)) {
		index = line.find(pars);
		if (index == std::string::npos)
			throw std::overflow_error("Invalid line");
		friend1 = line.substr(0, index);
		friend2 = line.substr(index + pars.length());
		_map[friend1].push_back(friend2);
		_map[friend2].push_back(friend1);
	}
	if (opt == 1) {
		try {
			_n = std::stoi(std::string(av[2]));
		} catch (std::exception &ex) {
			throw std::overflow_error("Invalid size n");
		}
		if (_n <= 0)
			throw std::overflow_error("Invalid size n");
	} else if (opt == 2)
		_toComp = std::make_pair(av[2], av[3]);
	for (auto &it : _map) {
		tmp.clear();
		for (auto &i : _map) {
			if (it.first == i.first || !existName(i.second, it.first))
				tmp[i.first] = 0;
			else
				tmp[i.first] = 1;
		}
		_matrice[it.first] = tmp;
	}
	_final = _matrice;
	_newMatrice = _matrice;
}

Separation::~Separation()
{
}

static int	multLine(std::map<std::string, std::map<std::string, int> > first,
					std::map<std::string, std::map<std::string, int> > second,
					std::vector<std::string> index, int x, int y)
{
	int	result = 0;

	for (unsigned int i = 0; i < first.size(); i++) {
		result += first[index[x]][index[i]] * second[index[i]][index[y]];
	}
	return result;
}

static std::map<std::string, std::map<std::string, int> >	multMatrice(
	std::map<std::string, std::map<std::string, int> > first,
	std::map<std::string, std::map<std::string, int> > second)
{
	std::map<std::string, std::map<std::string, int> >	result;
	std::vector<std::string>							index;
	std::map<std::string, int>							tmp;

	for (auto &it : first)
		index.push_back(it.first);
	result = first;
	for (unsigned int i = 0; i < first.size(); i++) {
		for (unsigned int s = 0; s < first.size(); s++)
			result[index[i]][index[s]] += multLine(first, second, index, i, s);
	}
	for (unsigned int i = 0; i < index.size(); i++)
		result[index[i]][index[i]] = 0;
	return result;
}

static void	affMatrice(std::map<std::string, std::map<std::string, int> > map)
{
	unsigned int	s = 0;

	for (auto &it : map) {
		s = 0;
		for (auto &i : it.second) {
			std::cout << i.second;
			if (s + 1 < it.second.size())
				std::cout << " ";
			s++;
		}
		std::cout << std::endl;
	}
}

void	Separation::fillFinal()
{
	for (auto &it : _newMatrice) {
		for (auto &i : it.second) {
			if (_newMatrice[it.first][i.first] >= 1 && _final[it.first][i.first] == 0)
				_final[it.first][i.first] = _current;
		}
	}
}

void	Separation::globalMatrice(int i)
{
	_newMatrice = multMatrice(_newMatrice, _matrice);
	_current = i + 1;
	fillFinal();
}

void	Separation::resultMatrice()
{
	for (int i = 1; i < _n && i < (int)_map.size(); i++)
		globalMatrice(i);
	for (auto &it : _map)
		std::cout << it.first << std::endl;
	std::cout << std::endl;
	affMatrice(_matrice);
	if (_n >= 6)
		return ;
	std::cout << std::endl;
	affMatrice(_final);
}

void	Separation::simpleConnect()
{
	int	degree;

	std::cout << "degree of separation between " << _toComp.first <<
				 " and " << _toComp.second << ": ";
	if (_toComp.first == _toComp.second)
		degree = 0;
	else if (_map[_toComp.first].size() == 0  || _map[_toComp.second].size() == 0)
		degree = -1;
	else {
		for (unsigned int i = 1; i < _map.size(); i++) {
			globalMatrice(i);
			if (i >= 3 || (degree = _final[_toComp.first][_toComp.second]) >= 1)
				break ;
		}
		if (degree == 0)
			degree = -1;
	}
	std::cout << degree << std::endl;
}
