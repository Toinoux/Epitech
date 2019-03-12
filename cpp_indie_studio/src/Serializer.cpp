//
// EPITECH PROJECT, 2018
// Serializer
// File description:
// BBM Project
//

#include <cstring>
#include <iostream>

#include <algorithm>
#include "Serializer.hpp"

std::string bbm::Serializer::makeCommand(int id, int command,
					 const std::string &args)
{
	std::string tmp("00");

	tmp[0] = id;
	tmp[1] = command;
	tmp.append(args);
	tmp.append("\r");
	return (tmp);
}

std::string bbm::Serializer::makeCommand(int id, int command,
					 int args)
{
	std::string tmp("000");

	tmp[0] = id;
	tmp[1] = command;
	tmp[2] = args;
	tmp.append("\r");
	return (tmp);
}

bbm::Command bbm::Serializer::extractCommand(const std::string &cmd)
{
	return static_cast<bbm::Command>(cmd.c_str()[1]);
}

bbm::Command bbm::Serializer::extractId(const std::string &cmd)
{
	return static_cast<bbm::Command>(cmd.c_str()[0]);
}

std::string bbm::Serializer::extractArgs(const std::string &cmd)
{
	std::string tmp = cmd.substr(1);

	tmp.erase(std::remove(tmp.begin(), tmp.end(), '\r'), tmp.end());
	return tmp;
}

bool bbm::Serializer::isOk(const std::string &cmd)
{
	auto len = cmd.size();
	if (len < 2)
		return false;
	bbm::Command command = extractCommand(cmd);
	std::cout << "size: " << len << "\n"
		  << command << " > " << FIRST_CMD << "\n"
		  << command << " < " << LAST_CMD << "\n";
	return (command < LAST_CMD &&
		command > FIRST_CMD);
}
