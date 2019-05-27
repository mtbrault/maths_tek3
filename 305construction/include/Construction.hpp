/*
** EPITECH PROJECT, 2018
** 305construction
** File description:
** Construction class
*/

#ifndef CONSTRUCTION_HPP_
	#define CONSTRUCTION_HPP_

#include <unordered_map>
#include <memory>
#include "Task.hpp"

class Construction {
public:
	Construction(const std::string &);
	~Construction();

	void	run();

private:
	void		parsFile();
	void		algo();
	bool		isFinished();
	void		displayExecution();
	void		displayGraph();
	std::string								_filename;
	std::vector<std::string>				_begin;
	std::unordered_map<std::string, std::shared_ptr<Task> >	_task;
	std::vector<std::pair<std::string, int> >	_executing;
};

#endif /* !CONSTRUCTION_HPP_ */
