/*
** EPITECH PROJECT, 2018
** 302separation
** File description:
** separation class
*/

#ifndef SEPARATION_HPP_
	#define SEPARATION_HPP_

#include <utility>
#include <vector>
#include <iostream>
#include <map>

class	Separation
{
public:
	Separation(char **, int);
	~Separation();
	void	simpleConnect();
	void	resultMatrice();

private:
	void	fillFinal();
	void	globalMatrice(int);
	std::vector<std::string>			_tmp;
	std::pair<std::string, std::string>	_toComp;
	int									_n;
	int									_current;
	std::map<std::string, std::vector<std::string> >	_map;
	std::map<std::string, std::map<std::string, int> >	_matrice;
	std::map<std::string, std::map<std::string, int> >	_newMatrice;
	std::map<std::string, std::map<std::string, int> >	_final;
};

#endif /* !SEPARATION_HPP_ */
