//
// EPITECH PROJECT, 2018
// Generator
// File description:
// INDIE PROJECT
//

#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include "Character/ACharacter.hpp"

namespace bbm {
	constexpr int MAX_HOLES = 20;
	constexpr int MIN_HOLES = 3;
	constexpr int MAX_STEPS = 30;
	constexpr int MIN_STEPS = 7;

	using mapPl = std::unordered_map<int, ACharacter>;
	using pair2f = std::pair<float, float>;

	class Generator {
	public:
		Generator() = default;
		~Generator() = default;

	public:
		void generateMap(std::string &map, mapPl &list) const;
		static void printMap(const std::string &map);

	private:
		void _makeHoles(std::string &map, int nbHoles) const;
		void _spawnPlayers(std::string &map, mapPl &list) const;
		void _createPlayer(std::string &map, int pos, ACharacter &pl)
			const;
		void _createHole(std::string &map, int x, int y, int step)
			const;
		void _fillWithWalls(std::string &map) const;
		void _generateCross(std::string &msg, int x, int y) const;
		void _linkPlayers(std::string &map, mapPl &list) const;
		bool _findPath(const std::string &map, pair2f pos1, pair2f pos2) const;
		void _createPath(std::string &map, pair2f pos1, pair2f pos2) const;
	};
}
