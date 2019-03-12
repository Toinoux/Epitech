//
// EPITECH PROJECT, 2018
// Utilities
// File description:
// Useful Class
//

#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "Arcade.hpp"
#include "Utilities.hpp"

bool arc::Utilities::isNumber(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

int	arc::Utilities::randInt(int min, int max)
{
	return (rand() % (max + 1 - min) + min);
}

std::vector<arc::Block> arc::Utilities::createMap
(size_t row, size_t col, int val)
{
	std::vector<arc::Block> map;

	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			arc::Vec2<float> pos(j, i);
			arc::Block b(val, pos);
			map.push_back(b);
		}
	}
	return (map);
}

void arc::Utilities::inputString(std::string &s, int key)
{
	if (key == arc::KeyCode::BACKSPACE && s.size() > 0)
		s.erase(s.size() - 1);
	if (key >= 33 && key <= 125)
		s = s + (char)key;
}

int	arc::Utilities::showUsage(const std::string &progname)
{
	std::cout << "USAGE" << std::endl;
	std::cout << "\t" + progname + " lib"
	<< std::endl << std::endl;
	std::cout << "DESCRIPTION" << std::endl;
	std::cout << "lib\tpath to a preference graphic library"
	<< std::endl;
	return (EXIT_SUCCESS);
}

std::string arc::Utilities::getFileExtension(const std::string &file_name) {

	size_t i = file_name.rfind('.', file_name.length());

	if (i != std::string::npos)
		return(file_name.substr(i + 1, file_name.length() - i));
	return("");
}

std::vector<std::string> arc::Utilities::readDir(const std::string &dir_path)
{
	DIR *dirp = opendir(dir_path.c_str());
	struct dirent *dp = readdir(dirp);
	std::vector<std::string> files_path;

	while (dp != NULL) {
		if (strcmp(dp->d_name, ".") != 0
			&& strcmp(dp->d_name, "..") != 0)
			files_path.push_back(dir_path + "/" + dp->d_name);
		if (dp != NULL)
			dp = readdir(dirp);
	}
	closedir(dirp);
	return (files_path);
}

std::string	arc::Utilities::getBaseName(const std::string &file_path)
{
	size_t i = file_path.rfind("/", file_path.length());
	std::string base_name("");

	if (i != std::string::npos)
		base_name = file_path.substr(i + 1, file_path.length() - i);
	i = base_name.find(PRE_LIB_NAME);
	if (i != std::string::npos)
		base_name = base_name.substr(i + strlen(PRE_LIB_NAME));
	i = base_name.rfind(".", base_name.length());
	if (i != std::string::npos)
		base_name = base_name.substr(0, i);
	return (base_name);
}

std::string	arc::Utilities::getFileContent(const std::string &file_path)
{
	std::ifstream ifs(file_path);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	return (content);
}
