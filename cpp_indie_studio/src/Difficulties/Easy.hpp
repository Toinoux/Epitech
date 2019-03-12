//
// EPITECH PROJECT, 2018
// Easy
// File description:
// Class
//

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include "ADifficulties.hpp"
#include "Character/ACharacter.hpp"

namespace bbm {

        class Easy : public ADifficulties {
        public:
                Easy(SocketManager &sock);
                ~Easy() = default;

        public:
                std::pair<float, float> findNewPos(float x, float y, std::string map) final;
                void setId(int id);
        
        private:
                std::pair<int, int> _setNewGoal(std::vector<std::pair<int, int>> pos);
                void _tryToPutBomb(std::pair<int, int> pos);
                void _tryToMove(std::pair<int, int> pos);
                std::vector<std::pair<int, int>> _checkPossibilities(std::string map, bbm::Texture texture);
                
        private:
                SocketManager _sock;

        };
}