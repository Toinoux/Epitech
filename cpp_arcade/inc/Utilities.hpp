//
// EPITECH PROJECT, 2018
// Utilities
// File description:
// Useful Class
//

#pragma once

#include <vector>
#include <string>
#include "Common.hpp"

namespace arc {
	class Utilities {
	public:
		static bool	isNumber(const std::string &);
		static int	randInt(int, int);
		static std::vector<Block> createMap(size_t, size_t, int v = -1);
		static void	inputString(std::string &, int);
		static int	showUsage(const std::string &);
		static std::string getFileExtension(const std::string &);
		static std::vector<std::string> readDir(const std::string &);
		static std::string getBaseName(const std::string &);
		static std::string getFileContent(const std::string &);
	};
}

#define EXIT_FAIL 84