/*
** EPITECH PROJECT, 2018
** 305construction
** File description:
** Task class
*/

#ifndef TASK_HPP_
	#define TASK_HPP_

#include <vector>
#include <iostream>
#include <utility>

class Task {
public:
	Task(const std::string &, int, std::vector<std::string>);
	~Task();

	int		getDuration() const;
	bool	isReady() const;
	void	newTask(const std::string &);
	void	execute(int);
	bool	isExecuted() const;
	int		getTime() const {return _time;};
	std::vector<std::pair<std::string, bool> >	getDepend() const {return _depend;};

private:
	std::string					_description;
	int							_duration;
	std::vector<std::pair<std::string, bool> >	_depend;
	bool						_isExecuted;
	int							_time;
};

#endif /* !TASK_HPP_ */
