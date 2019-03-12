/*
** EPITECH PROJECT, 2018
** ICore
** File description:
** ICore.hpp
*/

#pragma once
#include <vector>

#include "Serializer.hpp"

#define GET_MAP_VALUE(x, y) ((y) * MAP_SIZE + (x))

namespace bbm {
	constexpr int MAP_SIZE = 15;

	enum Texture {
		BLANK = 1,
		UNBREAKABLE_WALL,
		BREAKABLE_WALL,
		PLAYER,
		BOMB,
		POWERUP_SPEED,
	};

	/*
	** Lobby commands to interpret
	*/
	static const std::vector<bbm::Command> CMDS_LOBBY_SERVER({REQUEST_ID, ADD_SLOT, ADD_AI,
				SUB_SLOT, REQUEST_LAUNCH, MSG, PING, PONG});
	static const std::vector<bbm::Command> CMDS_LOBBY_CLIENT({LOBBY_DATA, MSG, LAUNCHED,
				PING, PONG, SEND_ID});

	/*
	** Game commands to interpret
	*/
	static const std::vector<bbm::Command> CMDS_GAME_CLIENT({MAP_DATA, PLAYER_DATA, DAMAGE,
				VICTORY, LOOSE, MSG, PING, PONG, QUIT});
	static const std::vector<bbm::Command> CMDS_GAME_SERVER({REQUEST_MOVE, REQUEST_BOMB,
				PING, PONG, MSG, QUIT, STOP_MOVING});

	class ICore {
	public:
		ICore() = default;
		virtual ~ICore() = default;

	public:
		virtual void run() = 0;

	private:
		virtual void _interpretCmd(const std::vector<Command> &cmds) = 0;
		virtual void _ping(int fd) = 0;
                virtual void _pong(int fd) = 0;
		virtual void _ping(int fd, const std::string &message) = 0;
                virtual void _pong(int fd, const std::string &message) = 0;
                virtual void _msg(int fd, const std::string &message) = 0;
	};
}
