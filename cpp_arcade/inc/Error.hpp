//
// EPITECH PROJECT, 2018
// Error
// File description:
// Arcade Exception
//

#pragma once

#include <exception>
#include <string>

constexpr char NO_LIBS[] = "No graphical libraries found";
constexpr char NO_GAMES[] = "No games found";
constexpr char CANT_LOAD_LIB[] = "Can't load library";
constexpr char CANT_LOAD_GAME[] = "Can't load game";

namespace arc {
	class ArcadeError : public std::exception
	{
	public:
		ArcadeError(std::string const &message) : _message(message) {}
		~ArcadeError() throw() {};
		const char *what() const throw() { return _message.data(); }
	private:
		std::string _message;
	};
}
