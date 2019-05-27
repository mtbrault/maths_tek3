/*
** EPITECH PROJECT, 2018
** 304pacman
** File description:
** Pacman class
*/

#ifndef PACMAN_HPP_
	#define PACMAN_HPP_

#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>

class Pacman {
public:
	Pacman(std::string, char, char);
	~Pacman();

	void	run();

private:
	bool									checkPath(int, int, int);
	bool									pathFind(int, int, int);
	std::pair<unsigned int, unsigned int>	getGhostPos();
	void									displayCell(int);
	std::unordered_map<std::string, int>	_convert;
	std::vector<std::vector<int> >	_map;
	std::unordered_map<int, std::vector<std::pair<int, int> > >	_algo;
	void		parsFile();
	std::string	_filename;
	char		_wall;
	char		_space;
	bool		_finished;
};

#endif /* !PACMAN_HPP_ */
