/*
** EPITECH PROJECT, 2018
** 303make
** File description:
** Make method
*/

#include <fstream>
#include "Make.hpp"

Make::Make()
	: _isGraph(true)
{
}

Make::~Make()
{
}

static bool	existFile(std::vector<std::string> list, std::string name)
{
	for (auto &it : list) {
		if (it == name)
			return true;
	}
	return false;
}

static std::vector<std::string>	parsLine(std::string line)
{
	std::vector<std::string>	val;
	auto						start = 0;
	auto						end = line.find(' ');
	while ("Infinite loop") {
		val.push_back(line.substr(start, end - start));
		if (end == std::string::npos)
			break ;
		start = end + 1;
		end = line.find(' ', start);
	}
	return val;
}

void	Make::setModified(const std::string &name)
{
	_modifiedFile = name;
	_isGraph = false;
}

void	Make::parseFile()
{
	std::ifstream				content(_makefileName);
	std::string					line;
	std::vector<std::string>	parsedLine;

	if (!content)
		throw std::overflow_error("Invalid file name");
	while (getline(content, line)) {
		if (line.size() == 0)
			continue ;
		parsedLine = parsLine(line);
		if (parsedLine[0][parsedLine[0].size() - 1] != ':')
			throw std::overflow_error("Not :");
		for (unsigned int i = 1; i < parsedLine.size(); i++) {
			_parsedGraph[parsedLine[0].substr(0, parsedLine[0].size() - 1)].push_back(parsedLine[i]);
			if (_parsedGraph[parsedLine[i]].size() == 0)
				_parsedGraph[parsedLine[i]].push_back("null");
		}
		if (!getline(content, line))
			throw std::overflow_error("No new line");
		_compile[parsedLine[0].substr(0, parsedLine[0].size() - 1)] = line;
	}
}

void	Make::createGraph()
{
	std::vector<std::string>	nameList;
	std::map<std::string, int>	map;

	for (auto &it : _parsedGraph)
		nameList.push_back(it.first);
	_lastGuy = nameList[nameList.size() - 1];
	for (auto &it : _parsedGraph) {
		map.clear();
		for (auto &i : nameList)
			map[i] = (existFile(_parsedGraph[it.first], i)) ? 1 : 0;
		_graph[it.first] = map;
	}
}

void	Make::displayGraph()
{
	for (auto &it : _graph) {
		std::cout << "[";
		for (auto &i : it.second) {
			std::cout << i.second;
			if (i.first != _lastGuy)
				std::cout << " ";
		}
		std::cout << "]" << std::endl;
	}
}

static void recursive(std::map<std::string, std::map<std::string, int> > graph,
					  std::string name, std::vector<std::string> listName)
{
	for (auto &it : listName) {
		if (graph[it][name] == 1) {
			std::cout << " -> " << it;
			recursive(graph, it, listName);
		}
	}
}

void	Make::displayDependencies()
{
	for (auto &it : _listName) {
		for (auto i : _listName) {
			if (_graph[i][it] == 1) {
				std::cout << it << " -> " << i;
				recursive(_graph, i, _listName);
				std::cout << std::endl;
			}
		}
	}
}

void	Make::displayCompile(std::string name)
{
	std::string	lastFile = "none";
	bool		found = false;

	for (auto &it : _listName) {
		if (it == _modifiedFile)
			found = true;
	}
	if (found == false)
		throw std::overflow_error("Unknow");
	for (auto &it : _listName) {
		if (_graph[it][name] == 1) {
			std::cout << _compile[it] << std::endl;
			lastFile = it;
		}
	}
	if (lastFile != "none")
		displayCompile(lastFile);
}

void	Make::run()
{
	parseFile();
	createGraph();
	for (auto &it : _parsedGraph)
		_listName.push_back(it.first);
	if (_isGraph) {
		displayGraph();
		std::cout << std::endl;
		displayDependencies();
	}
	else
		displayCompile(_modifiedFile);
}