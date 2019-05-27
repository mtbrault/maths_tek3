/*
** EPITECH PROJECT, 2018
** 304pacman
** File description:
** Pacman method
*/

#include <fstream>
#include "Pacman.hpp"

Pacman::Pacman(std::string filename, char wall, char space)
	: _filename(filename), _wall(wall), _space(space), _finished(false)
{
	_convert["pacman"] = -1;
	_convert["ghost"] = -2;
	_convert["space"] = -3;
	_convert["wall"] = -4;
}

Pacman::~Pacman()
{
}

void	Pacman::parsFile()
{
	std::ifstream		content(_filename);
	std::string			line;
	std::vector<int>	tmp;
	bool				isGhost = false;
	bool				isPacman = false;

	if (!content)
		throw std::overflow_error("Invalid file name");
	while (getline(content, line)) {
		tmp.clear();
		if (line.length() == 0)
			continue ;
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line[i] == '0')
				tmp.push_back(_convert["space"]);
			else if (line[i] == '1')
				tmp.push_back(_convert["wall"]);
			else if (line[i] == 'P' && isPacman == false) {
				isPacman = true;
				tmp.push_back(_convert["pacman"]);
			}
			else if (line[i] == 'F' && isGhost == false) {
				isGhost = true;
				tmp.push_back(_convert["ghost"]);
			}
			else
				throw std::overflow_error("Problem during parsing");
		}
		_map.push_back(tmp);
		if (tmp.size() != _map[0].size())
			throw std::overflow_error("Not same size in map");
	}
	if (isGhost == false || isPacman == false)
		throw std::overflow_error("Need a pacman and a ghost");
}

std::pair<unsigned int, unsigned int>	Pacman::getGhostPos()
{
	for (unsigned int x = 0; x < _map.size(); x++) {
		for (unsigned int y = 0; y < _map[x].size(); y++) {
			if (_map[x][y] == _convert["ghost"])
				return std::make_pair(x, y);
		}
	}
	return std::make_pair(0, 0);
}

bool	Pacman::checkPath(int x, int y, int i)
{
	if (x < 0 || x >= (int)_map.size() || y < 0 || y >= (int)_map[0].size())
		return false;
	else if (_map[x][y] == _convert["space"]) {
		_map[x][y] = i;
		_algo[i].push_back(std::make_pair(x, y));
	}
	else if (_map[x][y] == _convert["pacman"]) {
		_finished = true;
		return true;
	}
	return false;
}

bool	Pacman::pathFind(int x, int y, int i)
{
	if (checkPath(x - 1, y, i) || checkPath(x, y + 1 , i)
	|| checkPath(x + 1, y, i) || checkPath(x, y - 1, i))
		return true;
	return false;
}

void	Pacman::displayCell(int val)
{
	if (val == _convert["pacman"])
		std::cout << "P";
	else if (val == _convert["ghost"])
		std::cout << "F";
	else if (val == _convert["space"])
		std::cout << _space;
	else if (val == _convert["wall"])
		std::cout << _wall;
	else
		std::cout << (val % 10);
}

void	Pacman::run()
{
	parsFile();
	_algo[0].push_back(getGhostPos());
	//std::cout << _algo[0][0].first << " " << _algo[0][0].second;exit(0);
	for (int i = 0; !_finished; i++) {
		if (_algo[i].size() == 0)
			break ;
		for (auto &it : _algo[i]) {
			if (pathFind(it.first, it.second, i + 1))
				break ;
		}
	}
	if (_finished == false)
		throw std::overflow_error("No path");
	for (auto &it : _map) {
		for (auto &i : it)
			displayCell(i);
		std::cout << std::endl;
	}
}