/*
** EPITECH PROJECT, 2018
** 305construction
** File description:
** Construction method
*/

#include <fstream>
#include "Construction.hpp"

Construction::Construction(const std::string &filename)
	: _filename(filename)
{
}

Construction::~Construction()
{
}

static	std::vector<std::string>	parsLine(std::string line)
{
	std::vector<std::string>	val;	
	auto						start = 0;
	auto						end = line.find(';');
	while ("Yaniss is still an handsome man") {
		val.push_back(line.substr(start, end - start));
		if (end == std::string::npos)
			break ;
		start = end + 1;
		end = line.find(';', start);
	}
	return val;
}

void	Construction::parsFile()
{
	std::ifstream	content(_filename);
	std::string		line;
	std::vector<std::string>	parsedLine;
	std::vector<std::string>	tmp;
	
	if (!content)
		throw std::overflow_error("Invalid file name");
	while (getline(content, line)) {
		if (line.length() == 0)
			continue ;
		tmp.clear();
		parsedLine = parsLine(line);
		if (parsedLine.size() < 3)
			throw std::overflow_error("Bad line in file");
		else if (parsedLine.size() == 3)
			_begin.push_back(parsedLine[0]);
		for (unsigned int i = 3; i < parsedLine.size(); i++)
			tmp.push_back(parsedLine[i]);
		if (_task.find(parsedLine[0]) != _task.end())
			throw std::overflow_error("Problem during parsing");
		try {
			_task[parsedLine[0]] = std::make_shared<Task>(Task(parsedLine[1], std::stoi(parsedLine[2]), tmp));
		} catch (std::exception &ex) {
			throw std::overflow_error(ex.what());
		}
	}
}

bool	Construction::isFinished()
{
	for (auto &it : _task) {
		if (!it.second->isExecuted())
			return false;
	}
	return true;
}

void	Construction::algo()
{
	int	nbReady;
	int	timer = 0;
	int	tmpTimer;
	std::unordered_map<std::string, std::shared_ptr<Task> >	stock;

	while (!isFinished()) {
		nbReady = 0;
		tmpTimer = 0;
		stock.clear();
		for (auto &it : _task) {
			if (it.second->isReady() && !it.second->isExecuted()) {
				stock[it.first] = it.second;
				if (tmpTimer < it.second->getDuration())
					tmpTimer = it.second->getDuration();
				nbReady++;
			}
		}
		for (auto &it : stock) {
			it.second->execute(timer);
			_executing.push_back(std::make_pair(it.first, timer));
			for (auto &i : _task)
				i.second->newTask(it.first);
		}
		timer += tmpTimer;
		if (nbReady == 0)
			throw std::overflow_error("Construction can't continue");
	}
}

void	Construction::displayExecution()
{
	int	stock;
	std::vector<std::pair<std::string, int> >	tmp;
	int	max;

	for (auto &it : _executing) {
		stock = 0;
		for (auto &i : _task[it.first]->getDepend()) {
			if (i.first == "tmp")
				break ;
			if (stock < (_task[i.first]->getTime() + _task[i.first]->getDuration()))
			 	stock = _task[i.first]->getTime() + _task[i.first]->getDuration();
		}
		tmp.push_back(std::make_pair(it.first, stock));
		if (it == _executing.back())
			max = stock + _task[it.first]->getDuration();
	}
	std::cout << "Total duration of construction: " << max << ((max > 1) ? " weeks" : "week") << std::endl << std::endl;
	for (auto &it : tmp)
		std::cout << it.first << " must begin at t=" << it.second << std::endl;
}

void	Construction::displayGraph()
{
	std::cout << std::endl;
	for	(auto &it : _executing) {
		std::cout << it.first << "\t" << "(0)" << "\t";
		for (int i = 0; i < it.second; i++)
			std::cout << " ";
		for (int i = 0; i < _task[it.first]->getDuration(); i++)
			std::cout << "=";
		std::cout << std::endl;
	}
}

void	Construction::run()
{
	this->parsFile();
	this->algo();
	this->displayExecution();
	this->displayGraph();
}