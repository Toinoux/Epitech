//
// EPITECH PROJECT, 2018
// DefaultBomb
// File description:
// Class
//

#pragma once
#include "Timer.hpp"
#include "ABomb.hpp"
#include "Object/APowerUp/APowerUp.hpp"

namespace bbm {
	constexpr int SECONDS_BEFORE_EXPLOSION = 3;
	constexpr int RANGE = 2;
	class DefaultBomb : public ABomb {
	public:
		DefaultBomb() = delete;
		DefaultBomb(int x, int y);
		~DefaultBomb() = default;

	public:
		bool checkDetonation() override;
		void detonate(std::string &map,
			std::unordered_map<int, ACharacter> &players,
			std::vector<std::unique_ptr<ABomb>> &bombs,
			std::vector<std::unique_ptr<APowerUp>> &powers) override;

	private:
		Timer _clock;
	};
}
