//
// EPITECH PROJECT, 2018
// SocketManager
// File description:
// cpp
//

#ifdef LINUX
#include <sys/time.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <sys/un.h>
#endif /* !LINUX */

#include <stdexcept>
#include <iostream>
#include <cstring>
#include "SocketManager.hpp"

#ifdef LINUX
bbm::SocketManager::SocketManager(int port)
	: _sock(socket(AF_INET, SOCK_STREAM, 0)), _port(port), _ip("127.0.0.1"), _isServer(true)
{
	int option = 1;

	_timeout.tv_sec = 0;
	_timeout.tv_usec = 500;
	FD_ZERO(&_readFd);
	FD_ZERO(&_writeFd);
	if (_sock == -1)
		throw std::runtime_error("Failed to bind socket.");
	setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(_sock, (struct sockaddr *)&_addr,
		 sizeof(struct sockaddr_in)) == -1)
		throw std::runtime_error("Failed to bind socket.");
	if (listen(_sock, bbm::QUEUE_LISTEN_SIZE) == -1)
		throw std::runtime_error("Failed to listen on socket.");
}

bbm::SocketManager::SocketManager(const std::string &ip, int port)
	: _sock(socket(AF_INET, SOCK_STREAM, 0)), _port(port), _ip(ip), _isServer(false)
{
	int option = 1;

	std::cout << "CREATING CONNECT" << std::endl;
	_timeout.tv_sec = 0;
	_timeout.tv_usec = 500;
	FD_ZERO(&_readFd);
	FD_ZERO(&_writeFd);
	if (_sock == -1)
		throw std::runtime_error("Failed to bind socket.");
	setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	inet_pton(AF_INET, ip.c_str(), &(_addr.sin_addr));
	if (connect(_sock, (struct sockaddr *)&_addr,
		    sizeof(struct sockaddr)) == -1)
		throw std::runtime_error("Failed to connect to the server.");
	std::cout << "LEAVING CREATING CONNECT" << std::endl;
}

bbm::SocketManager::~SocketManager()
{
	close(_sock);
}
#endif /* !LINUX */

#ifdef WIN32
bbm::SocketManager::SocketManager(int port) : _port(port), _ip("127.0.0.1"), _isServer(true)
{
	int option = 1;

	WSAStartup(MAKEWORD(2,0), &_wsaData);
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	_timeout.tv_sec = 0;
	_timeout.tv_usec = 500;
	FD_ZERO(&_readFd);
	FD_ZERO(&_writeFd);
	if (_sock == -1)
		throw std::runtime_error("Failed to bind socket.");
	setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(_sock, (struct sockaddr *)&_addr,
		 sizeof(struct sockaddr_in)) == -1)
		throw std::runtime_error("Failed to bind socket.");
	if (listen(_sock, bbm::QUEUE_LISTEN_SIZE) == -1)
		throw std::runtime_error("Failed to listen on socket.");
}

bbm::SocketManager::SocketManager(const std::string &ip, int port)
	: _port(port), _ip(ip), _isServer(false)
{
	int option = 1;

	WSAStartup(MAKEWORD(2,0), &_wsaData);
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	_timeout.tv_sec = 0;
	_timeout.tv_usec = 500;
	FD_ZERO(&_readFd);
	FD_ZERO(&_writeFd);
	if (_sock == -1)
		throw std::runtime_error("Failed to bind socket.");
	setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	if (connect(_sock, (struct sockaddr *)&_addr,
		    sizeof(struct sockaddr)) == -1)
		throw std::runtime_error("Failed to connect to the server.");
}

bbm::SocketManager::~SocketManager()
{
	closesocket(_sock);
	WSACleanup();
}
#endif /* !WIN32 */

void bbm::SocketManager::_doSelect(int fd)
{
	int max = _sock;

	FD_SET(_sock, &_readFd);
	if (_isServer == false)
		FD_SET(_sock, &_writeFd);
	FD_SET(fd, &_readFd);
	FD_SET(fd, &_writeFd);
	if (fd > max)
		max = fd;
	if (select(max + 1, &_readFd, &_writeFd, NULL, &_timeout) == -1)
		throw std::runtime_error("Select failed.");
}

int bbm::SocketManager::acceptSocket()
{
	int newClient;
	struct sockaddr addr;
	socklen_t size = sizeof(addr);

	_doSelect();
	if (FD_ISSET(_sock, &_readFd)) {
		newClient = accept(_sock, &addr, &size);
		if (newClient == -1)
			throw std::runtime_error("Failed to accept.");
		return (newClient);
	}
	return (-1);
}

void bbm::SocketManager::sendMsg(int fd, const std::string &msg)
{
	_doSelect(fd);
	if (_isServer == false && FD_ISSET(_sock, &_writeFd)) {
		_send(_sock, msg.c_str(), msg.size());
		return;
	}
	if (FD_ISSET(fd, &_writeFd))
		_send(fd, msg.c_str(), msg.size());
}

void bbm::SocketManager::recvMsg(int fd, std::string &msg)
{
	char buff[4096];

	_doSelect(fd);
	msg.clear();
	if (_isServer == false && FD_ISSET(_sock, &_readFd)) {
		std::memset(buff, 0, 4096);
		_recv(_sock, buff);
		msg.append(buff);
		return;
	}
	if (FD_ISSET(fd, &_readFd)) {
		std::memset(buff, 0, 4096);
		_recv(fd, buff);
		msg.append(buff);
	}
}

void bbm::SocketManager::_doSelect(const std::vector<int> &clients)
{
	int max = _sock;

	FD_SET(_sock, &_readFd);
	if (_isServer == false)
		FD_SET(_sock, &_writeFd);
	for (auto &it : clients) {
		FD_SET(it, &_readFd);
		FD_SET(it, &_writeFd);
		if (it > max)
			max = it;
	}
	if (select(max + 1, &_readFd, &_writeFd, NULL, &_timeout) == -1)
		throw std::runtime_error("Select failed.");
}

void bbm::SocketManager::_doSelect()
{
	FD_SET(_sock, &_readFd);
	if (_isServer == false)
		FD_SET(_sock, &_writeFd);
	if (select(_sock + 1, &_readFd, &_writeFd, NULL, &_timeout) == -1)
		throw std::runtime_error("Select failed.");
}

void bbm::SocketManager::sendMsg(const std::vector<int> &clients,
				 const std::string &msg)
{
	_doSelect(clients);
	for (const auto &fd : clients) {
		if (FD_ISSET(fd, &_writeFd)) {
			_send(fd, msg.c_str(), msg.size());
		}
	}
}

void bbm::SocketManager::sendMsg(const std::string &msg)
{
	_doSelect();
	if (FD_ISSET(_sock, &_writeFd))
		_send(_sock, msg.c_str(), msg.size());
}

void bbm::SocketManager::recvMsg(std::string &msg)
{
	char buff[4096];

	_doSelect(_sock);
	msg.clear();
	if (FD_ISSET(_sock, &_readFd)) {
		std::memset(buff, 0, 4096);
		_recv(_sock, buff);
		msg.append(buff);
	}
}

void bbm::SocketManager::_recv(int sock, char *buff)
{
	int tmp = recv(sock, buff, 4095, 0);

	if (tmp == -1)
		throw std::runtime_error("Failed to receive.");
	if (tmp == 0)
		throw std::runtime_error("End of file.");
}

void bbm::SocketManager::_send(int fd, const char *str, size_t size)
{
	int tmp = send(fd, str, size, 0);
	if (tmp == -1)
		throw std::runtime_error("Failed to send.");
	if (tmp == 0)
	 	throw std::runtime_error("End of file.");
}
