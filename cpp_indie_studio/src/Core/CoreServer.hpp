/*
** EPITECH PROJECT, 2018
** CoreServer
** File description:
** class CoreServer
*/

#pragma once
#include <memory>
#include <functional>
#include <unordered_map>
#include "Character/ACharacter.hpp"
#include "Object/ABomb/ABomb.hpp"
#include "Object/APowerUp/APowerUp.hpp"
#include "ICore.hpp"
#include "CoreAI.hpp"
#include "CorePlayer.hpp"
#include "SocketManager.hpp"
#include "IEntity.hpp"
#include "Serializer.hpp"
#include "Parser.hpp"
#include "Threads/ThreadPool.hpp"

namespace bbm {

	class CoreServer : public ICore {
	public:
		CoreServer() = delete;
		CoreServer(int port, int nbPlayers);
		CoreServer(const CoreServer &coreServer) = delete;
		~CoreServer();
		CoreServer &operator=(CoreServer &coreServer) = delete;

	public:
		void _managePlayer();
		void _launchAI();
		void run() final;
		inline void setNbPlayer(char nbPlayers);
		inline char getNbPlayer() const;

	private:
		/*
		** Functions to send commands to the clients
		*/
		void _lobbyData();
		void _mapData();
		void _playerData();
		void _launched();
		void _ping(int fd) final;
		void _pong(int fd) final;
		void _sendId(int fd);
		void _damage(int fd);
		void _victory(std::vector<int> playerList);
		void _loose(std::vector<int> playerList);

		/*
		** Functions to interpret requests from the clients
		*/
		void _ping(int fd, const std::string &message) final;
		void _pong(int fd, const std::string &message) final;
		void _msg(int fd, const std::string &message) final;
		void _sendId(int fd, const std::string &message);
		void _requestLaunch(int fd, const std::string &message);
		void _addSlot(int fd, const std::string &message);
		void _subSlot(int fd, const std::string &message);
		void _requestId(int fd, const std::string &message);
		void _requestMove(int fd, const std::string &message);
		void _stopMoving(int fd, const std::string &message);
		void _requestBomb(int fd, const std::string &message);
		void _movePos(int pos, float &x, float &y);
		bool _checkCollide(float &x, float &y);
		void _quit(int fd, const std::string &message);

		void _interpretCmd(const std::vector<bbm::Command> &cmds) final;
		void _updateWorld();
		void _updateBombs();
		void _updatePlayers();
		void _updatePowerUps();
		void _movePlayer(bbm::ACharacter &player);
		bool _checkCollideWall(float x, float y);
		bool _checkCollideBomb(float x, float y);
		bool _checkBorder(float x, float y);
		void _removeGarbage();

		/*
		** Class variables
		*/
		using funcPtr = void (bbm::CoreServer::*)(int fd, const std::string &message);
		enum {
			NONE = -2,
			SERVER,
		};
		ThreadPool _tp;
		bool _isEnded;
		int _adminFd;
		std::string _map;
		SocketManager _sock;
		std::vector<IEntity> _entity;
		size_t _nbPlayers;
		size_t _nbAI;
		std::unordered_map<int, ACharacter> _playerList;
		std::vector<std::unique_ptr<ABomb>> _bombList;
		std::vector<std::unique_ptr<APowerUp>> _powerList;
		std::vector<std::unique_ptr<CoreAI>> _aiList;
		bool _isLaunched = false;
		std::unordered_map<bbm::Command, funcPtr> _execCmd = {
			{ Command::PING, &bbm::CoreServer::_pong },
			{ Command::PONG, &bbm::CoreServer::_ping },
			{ Command::MSG, &bbm::CoreServer::_msg },
			{ Command::REQUEST_LAUNCH, &bbm::CoreServer::_requestLaunch },
			{ Command::ADD_SLOT, &bbm::CoreServer::_addSlot },
			{ Command::ADD_AI, &bbm::CoreServer::_addSlot },
			{ Command::SUB_SLOT, &bbm::CoreServer::_subSlot },
			{ Command::REQUEST_ID, &bbm::CoreServer::_requestId },
			{ Command::REQUEST_MOVE, &bbm::CoreServer::_requestMove },
			{ Command::STOP_MOVING, &bbm::CoreServer::_stopMoving },
			{ Command::QUIT, &bbm::CoreServer::_quit },
			{ Command::REQUEST_BOMB, &bbm::CoreServer::_requestBomb }
		};
	};
}

void bbm::CoreServer::setNbPlayer(const char nbPlayers)
{
	_nbPlayers = nbPlayers;
}

char bbm::CoreServer::getNbPlayer() const
{
	return _nbPlayers;
}
