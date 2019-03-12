/*
** EPITECH PROJECT, 2018
** CoreClient
** File description:
** class CoreClient
*/

#pragma once
#include <algorithm>
#include <unordered_map>
#include <string>
#include <utility>

#include "ICore.hpp"
#include "SocketManager.hpp"
#include "Parser.hpp"
#include "Serializer.hpp"
#include "Character/ACharacter.hpp"

namespace bbm {

	constexpr int TICKRATE = 1000 / 30;

	class CoreClient : public ICore {
	public:
		CoreClient() = delete;
		CoreClient(int port, const std::string &ipAddr, ACharacter character);
		CoreClient(const CoreClient &coreClient) = delete;
		~CoreClient();
		CoreClient &operator=(CoreClient &coreClient) = delete;

	public:
		virtual void run() = 0;
		inline ACharacter &getCharacter();
		inline const std::string &getMap() { return _map; };
		inline const int &getID() { return _id; };

	protected:
		using cmdPtr = void (bbm::CoreClient::*)(int fd, const std::string &message);
		void _getNewID();
		void _interpretCmd(const std::vector<Command> &cmds) final;
		void _createPlayerList();

		/*
		** Functions to send requests to the server
		*/
	public:
		void _requestMove(Direction direction);
		void _requestBomb();
		void _requestLaunch();
		void _requestId();
		void _addSlot(int nbSlot, Command cmd);
		void _subSlot(int nbSlot);
		void _pong(int fd) final;
		void _ping(int fd) final;
		void _stopMoving();
		void quit();
		const std::unordered_map<int, ACharacter> &getPlayers() const;

		/*
		** Functions to interpret commands from the server
		*/
	protected:
		void _msg(int fd, const std::string &message) final;
		void _ping(int fd, const std::string &message) final;
		void _pong(int fd, const std::string &message) final;
		void _lobbyData(int fd, const std::string &message);
		void _mapData(int fd, const std::string &message);
		void _playerData(int fd, const std::string &message);
		void _launched(int fd, const std::string &message);
		void _damage(int fd, const std::string &message);
		void _victory(int fd, const std::string &message);
		void _loose(int fd, const std::string &message);
		void _sendId(int fd, const std::string &message);
		void _quit(int fd, const std::string &);

		/*
		** Class variables
		*/
		ACharacter &_character;
		bool _isLaunched;
		bool _isEnded;
		int _id;
		char _nbPlayers;
		std::string _map;
		SocketManager _sock;
		std::unordered_map<int, ACharacter> _playerList;
		std::unordered_map<bbm::Command, cmdPtr> _execCmd = {
			{ Command::LAUNCHED, &bbm::CoreClient::_launched },
			{ Command::MAP_DATA, &bbm::CoreClient::_mapData },
			{ Command::PLAYER_DATA, &bbm::CoreClient::_playerData },
			{ Command::LOBBY_DATA, &bbm::CoreClient::_lobbyData },
			{ Command::VICTORY, &bbm::CoreClient::_victory },
			{ Command::LOOSE, &bbm::CoreClient::_loose },
			{ Command::MSG, &bbm::CoreClient::_msg },
			{ Command::DAMAGE, &bbm::CoreClient::_damage },
			{ Command::PING, &bbm::CoreClient::_pong },
			{ Command::SEND_ID, &bbm::CoreClient::_sendId },
			{ Command::PONG, &bbm::CoreClient::_ping },
			{ Command::QUIT, &bbm::CoreClient::_quit }
		};
	};
}

bbm::ACharacter &bbm::CoreClient::getCharacter()
{
	return _character;
}
