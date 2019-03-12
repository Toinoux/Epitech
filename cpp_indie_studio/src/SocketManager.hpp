//
// EPITECH PROJECT, 2018
// SocketManager
// File description:
// Header
//

#pragma once

#ifdef LINUX
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#endif /* !LINUX */

#ifdef WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>
#endif /* !WIN32 */

#include <string>
#include <vector>

namespace bbm {

	constexpr int QUEUE_LISTEN_SIZE = 100;
	constexpr int DEFAULT_PORT = 42069;
	constexpr char DEFAULT_IP[] = "127.0.0.1";

	class SocketManager {
	public:
		SocketManager() = default;
		SocketManager(int port);
		SocketManager(const std::string &ip, int port);
		~SocketManager();

	public:
		int acceptSocket();
		void sendMsg(int fd, const std::string &msg);
		void sendMsg(const std::vector<int> &clients,
			     const std::string &msg);
		void sendMsg(const std::string &msg);
		void recvMsg(int fd, std::string &msg);
		void recvMsg(std::string &msg);
		inline int getPort() const;
		inline const std::string &getIP() const;

	private:
		void _doSelect();
		void _doSelect(int fd);
		void _doSelect(const std::vector<int> &clients);
		void _recv(int sock, char *buff);
		void _send(int fd, const char *str, size_t size);

	private:
	    #ifdef WIN32
	    WSADATA _wsaData;
	    #endif // WIN32
		int _sock;
		int _port;
		std::string _ip;
		bool _isServer;
		struct timeval _timeout;
		int _client;
		struct sockaddr_in _addr;
		fd_set _readFd;
		fd_set _writeFd;
	};
}

void sigpipeHandler(int sig);

int bbm::SocketManager::getPort() const
{
	return _port;
}

const std::string &bbm::SocketManager::getIP() const
{
	return _ip;
}
