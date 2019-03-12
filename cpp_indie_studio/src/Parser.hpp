//
// EPITECH PROJECT, 2018
// Parser
// File description:
// class
//

#pragma once
#include <vector>
#include <iostream>
#include <string>

namespace bbm {

	enum State {
		NO_EXIST = -2,
		NO_VALUE
	};

	extern std::string g_ip;
	extern int g_port;
	class Parser {
	public:
		Parser();
		~Parser();

	public:
		void parsArgs(int ac, const char **av);
		static void parseCmds(std::vector<std::string> &cmds,
				      std::string msg);

		void printArgs();
		int checkArgs(const std::string &to_check) const;
		std::string parseIP(int ac, const char **av);

	private:
		std::vector<std::string> _argsType;
		std::vector<int> _argsValue;
		std::string _ip;
	};
}
