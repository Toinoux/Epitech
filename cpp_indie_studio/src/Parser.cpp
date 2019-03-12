//
// EPITECH PROJECT, 2018
// Parser
// File description:
// class
//

#include <algorithm>
#include "Parser.hpp"

bbm::Parser::Parser()
{}

bbm::Parser::~Parser()
{}

void bbm::Parser::printArgs()
{
	for (size_t i = 0; i < _argsType.size(); i++)
		std::cout << "[" << _argsType[i] << "] -> ("
			  << std::to_string(_argsValue[i]) << ")" << std::endl;
}

int bbm::Parser::checkArgs(const std::string &to_check) const
{
	size_t i = 0;

	for (;  i < _argsType.size(); i++) {
		if (_argsType[i] == to_check)
			return _argsValue[i];
	}
	return NO_EXIST;
}

void bbm::Parser::parsArgs(int ac, const char **av)
{
	std::string arg;
	int value;
	int pos;

	for (int i = 1; i < ac; i++) {
		arg = av[i];
		arg.erase(0,2);
		pos = arg.find('=');
		_argsType.push_back(arg.substr(0, pos));
		arg.erase(0, pos + 1);
		value = (pos > 0) ? atoi(arg.c_str()) : NO_VALUE;
		_argsValue.push_back(value);
	}
}

std::string bbm::Parser::parseIP(int ac, const char **av)
{
	std::string arg;
	std::string value;
	int pos;

	for (int i = 1; i < ac; i++) {
		arg = av[i];
		arg.erase(0,2);
		pos = arg.find('=');
		_argsType.push_back(arg.substr(0, pos));
		arg.erase(0, pos + 1);
		value = (pos > 0) ? (arg.c_str()) : nullptr;
		_ip = value;
	}
	return (_ip);
}

void bbm::Parser::parseCmds(std::vector<std::string> &cmds, std::string msg)
{
	size_t pos;

	cmds.clear();
	while ((pos = msg.find('\r')) != std::string::npos) {
		if (msg.substr(0, pos).size() != 0)
			cmds.push_back(msg.substr(0, pos));
		msg.erase(0, pos + 1);
	}
	if (msg.size() != 0)
		cmds.push_back(msg);
}
