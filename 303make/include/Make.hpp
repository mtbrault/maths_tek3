/*
** EPITECH PROJECT, 2018
** 303make
** File description:
** Make class
*/

#ifndef MAKE_HPP_
	#define MAKE_HPP_

#include <vector>
#include <iostream>
#include <map>

class Make {
	public:
		Make();
		~Make();

		void	run();
		void	setModified(const std::string &);
		void	setMakefile(const std::string &name) {_makefileName = name;};
		
	private:
		void			parseFile();
		void			createGraph();
		void			displayGraph();
		void			displayDependencies();
		void			displayCompile(std::string);
		bool			_isGraph;
		std::string		_makefileName;
		std::string		_modifiedFile;
		std::string		_lastGuy;
		std::map<std::string, std::vector<std::string> >	_parsedGraph;
		std::map<std::string, std::string>					_compile;
		std::map<std::string, std::map<std::string, int> >	_graph;
		std::vector<std::string>							_listName;
};

#endif /* !MAKE_HPP_ */
