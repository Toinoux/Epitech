//
// EPITECH PROJECT, 2018
// CoreClientPlayer
// File description:
// class
//

#pragma once
#include "CoreClient.hpp"
#include "Character/Player.hpp"

namespace bbm {
	class CorePlayer : public CoreClient {
	public:
		CorePlayer(int port, const std::string &ipAddr);
		~CorePlayer() = default;

	public:
		void run();
		void enterLobby(int nbAI);
		bool inLobby();
		bool inGame();
	};
}
