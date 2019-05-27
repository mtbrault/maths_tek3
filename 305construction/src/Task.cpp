/*
** EPITECH PROJECT, 2018
** 305construction
** File description:
** Task method
*/

#include "Task.hpp"

Task::Task(const std::string &desc, int dur, std::vector<std::string> depend)
	: _description(desc), _duration(dur), _isExecuted(false)
{
	for (auto &it : depend)
		_depend.push_back(std::make_pair(it, false));
	if (depend.size() == 0)
		_depend.push_back(std::make_pair("tmp", true));
}

Task::~Task()
{
}

int	Task::getDuration() const
{
	return _duration;
}

void	Task::execute(int val)
{
	_isExecuted = true;
	_time = val;
}

bool	Task::isExecuted() const
{
	return _isExecuted;
}

bool	Task::isReady() const
{
	for (auto &it : _depend) {
		if (it.second == false)
			return false;
	}
	return true;
}

void	Task::newTask(const std::string &name)
{
	for (auto &it : _depend) {
		if (it.first == name)
			it.second = true;
	}
}