//
// EPITECH PROJECT, 2018
// ABomb
// File description:
// Abstract
//

#pragma once
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include "Object/AObject.hpp"
#include "Character/ACharacter.hpp"
#include "Object/APowerUp/APowerUp.hpp"

namespace bbm {
	class ABomb : public AObject {
	public:
		ABomb() = delete;
		ABomb(int x, int y);
		virtual ~ABomb() = default;

	public:
		std::pair<int, int> getPos() const;
		void setPos(int x, int y);
		bool getStatus() const;
		void setStatus(bool status) {_isActive = status;}
		virtual bool checkDetonation() = 0;
		virtual void detonate(std::string &map,
			std::unordered_map<int, ACharacter> &players,
			std::vector<std::unique_ptr<ABomb>> &bombs,
			std::vector<std::unique_ptr<APowerUp>> &powers) = 0;

	protected:
		bool _removeFromMap(std::string &map, int x, int y);
		void _checkPlayers(std::unordered_map<int, ACharacter> &players,
					int x, int y);
		void _checkBomb(int x, int y, std::string &map,
			std::unordered_map<int, ACharacter> &players,
			std::vector<std::unique_ptr<ABomb>> &bombs,
			std::vector<std::unique_ptr<APowerUp>> &powers);
		bool _checkCase(int x, int y, std::string &map,
			std::unordered_map<int, ACharacter> &players,
			std::vector<std::unique_ptr<ABomb>> &bombs,
			std::vector<std::unique_ptr<APowerUp>> &powers);

	protected:
		int _x;
		int _y;
		int _range;
		bool _isActive;
	};
}
