//
// EPITECH PROJECT, 2018
// IDifficulties
// File description:
// Interface
//

#pragma once
#include <iostream>
#include "Core/ICore.hpp"

namespace bbm {
        class IDifficulties {
        public:
                IDifficulties() = default;
                virtual ~IDifficulties() = default;

        public:
                virtual std::pair<float, float> findNewPos(float x, float y, std::string map) = 0;
        };
}