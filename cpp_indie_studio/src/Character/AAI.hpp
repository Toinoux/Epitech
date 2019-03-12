/*
** EPITECH PROJECT, 2018
** AAI
** File description:
** Abstract class AI
*/

#pragma once
#include <iostream>
#include <string>

#include "ACharacter.hpp"

namespace bbm {
	class AAI : public ACharacter {
	public:
		AAI() = delete;
		AAI(size_t id);
		AAI(const AAI &ai);
		virtual ~AAI() = default;
		AAI &operator=(AAI &ai);
	};
}
