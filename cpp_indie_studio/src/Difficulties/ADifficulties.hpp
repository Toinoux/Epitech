//
// EPITECH PROJECT, 2018
// ADifficulties
// File description:
// Abstract
//

#pragma once
#include "IDifficulties.hpp"
#include "SocketManager.hpp"


namespace bbm {
        class ADifficulties : public IDifficulties {
        public:
                ADifficulties();
                virtual ~ADifficulties() = default;
        
        public:
                virtual std::pair<float, float> findNewPos(float x, float y, std::string maps) override;

        protected:
                int _xAI;
                int _yAI;
                int _rand;
                float _xGoal;
                float _yGoal;
                int _id;
        };
}