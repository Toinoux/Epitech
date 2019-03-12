/*
** EPITECH PROJECT, 2018
** CoreCLientAI
** File description:
** class
*/

#pragma once
#include <memory>

#include "CoreClient.hpp"
#include "Character/AAI.hpp"
#include "Difficulties/Easy.hpp"

namespace bbm {
	class CoreAI : public CoreClient {
	public:
		CoreAI() = delete;
		CoreAI(int port, const std::string &ipAddr);
		CoreAI(const CoreAI &coreAI) = delete;
		~CoreAI();
		CoreAI &operator=(const CoreAI &coreAI) = delete;

	public:
		void run() final;

	private:
		enum COLLISIONS {
			ACCESSIBLE =  0,
			INACCESSIBLE
		};

		enum DANGERS {
			SAFE = 0,
			DANGEROUS
		};

		void _play();
		void _updateCollisions();
		void _updateDangers();

		std::string _collisionMap;
		std::string _dangerMap;
		Easy _difficultyAI;
	};
}
