//
// EPITECH PROJECT, 2018
// Serializer
// File description:
// BBM PROJECT
//

#pragma once
#include <string>

namespace bbm {
	enum Command {
		FIRST_CMD = 1,
		REQUEST_ID,
		SEND_ID,
		REQUEST_LAUNCH,
		LAUNCHED,
		MAP_DATA,
		PLAYER_DATA,
		LOBBY_DATA,
		ADD_SLOT,
		SUB_SLOT,
		ADD_AI,
		VICTORY,
		LOOSE,
		REQUEST_MOVE,
		STOP_MOVING,
		REQUEST_BOMB,
		DAMAGE,
		MSG,
		PING,
		PONG,
		QUIT,
		LAST_CMD
	};

	constexpr char YOU_ARE_ADMIN[] = "WP ! You are the admin of the lobby !";
	constexpr char NOT_AUTHORIZED[] = "Sorry, only the admin can do such a thing !";
	constexpr char SLOTS_ARE_FULL[] = "Oops, not enough slots in da place !";
	constexpr char NOT_ENOUGH_PLAYERS[] = "Oops, not enough players to start the game :/";
	constexpr char NEED_ID[] = "ID required !";
	constexpr char SUCCESSFUL[] = "Command okay !";
	constexpr char FAILURE[] = "Command failed !";
	constexpr char MSG_PONG[] = "PONG";
	constexpr char MSG_PING[] = "PING";

	enum {
		SERVERID = -1,
		NOID = -2
	};

	class Serializer {
	public:
		Serializer() = default;
		~Serializer() = default;

	public:
		static std::string makeCommand(int id, int command,
					       const std::string &args = "");
		static std::string makeCommand(int id, int command,
					       int args = 0);
		static Command extractCommand(const std::string &cmd);
		static bool isOk(const std::string &cmd);
		static Command extractId(const std::string &cmd);
		static std::string extractArgs(const std::string &cmd);
	};
}
