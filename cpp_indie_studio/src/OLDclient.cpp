#include <iostream>
#include <cstring>

#include <string>
#include <iostream>

#include <thread>
#include <functional>

#include "Serializer.hpp"
#include "SocketManager.hpp"

static const int TIME_OUT = 1;
static std::string username = "anonymous";

void print_intro()
{
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "| Welcome to the Indie Studio Client [3.7.4] |" << std::endl;
        std::cout << "----------------------------------------------\n" << std::endl;
        std::cout << "[CMD INDEX]:\tREQUEST_ID = 2,\t\tSEND_ID = 3,\t\tREQUEST_LAUNCH = 4,\tLAUNCHED = 5,\n\t\tMAP_DATA = 6,\t\tPLAYER_DATA = 7,\tLOBBY_DATA = 8,\t\tADD_SLOT = 9,\n\t\tSUB_SLOT = 10,\t\tADD_AI = 11,\t\tVICTORY = 12,\t\tLOOSE = 13,\n\t\tMOVE = 14,\t\tBOMB = 15,\t\tMSG = 16" << "\n\n\n";
}

void print_prompt()
{
        std::cout << "{" << username << "} [0/4] > ";
}

const std::string read_cmd()
{
	std::string tmp;
	int cmd;

	std::cin >> cmd;
	tmp[0] = cmd;
	printf("[%d]\n", tmp[0]);
	return tmp;
}

static void send_cmd(bbm::SocketManager &test, std::string cmd,
			 int &fd, std::string args = "")
{
        std::string tmp;

	if (cmd[0] == bbm::Command::ADD_SLOT)
		args[0] = 1;
	test.sendMsg(bbm::Serializer::makeCommand(fd, cmd[0], args));
        std::cout << "\nWaiting ...\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(TIME_OUT));
	test.recvMsg(tmp);
        if (tmp.size() > 0)
	        std::cout << "Server successfully answer" << "\n";
	if (bbm::Serializer::isOk(tmp))
		printf("SERVER CMD is OK !\n");
	if (cmd[0] == bbm::REQUEST_ID && fd < 0) {
                fd = tmp[2];
		printf("id: '%d'\n", fd);
		username = "Player_" + std::to_string(fd);
		std::cout << "[NEW FD]: " << fd << std::endl;
                std::cout << "[NEW USERNAME/ID]: " << username << std::endl;
	}
        if (tmp[1] == bbm::LAUNCHED) {
                std::cout << "Game is launch ! Let's gooo bitch\n";
        }
        if (tmp[1] == bbm::LOBBY_DATA) {
                std::cout << "Lobby data received !\n";
                std::cout << "nb players: " << std::to_string(tmp[1]) << std::endl;
        }
        std::cout << std::endl;
}

int main()
{
	bbm::SocketManager sock("127.0.0.1", 4242);
	int fd = -2;

        print_intro();
        while ('*') {
                print_prompt();
                auto cmd  = read_cmd();
		printf("{%d}\n", cmd[0]);
		if (cmd[0] > 1 && cmd[0] < 15)
                        send_cmd(sock, cmd, fd);
                else
                        std::cout << "\n/!\\ Invalide Command /!\\\n\n";
        }
        return 0;
}
