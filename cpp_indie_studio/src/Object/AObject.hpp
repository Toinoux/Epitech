/*
** EPITECH PROJECT, 2018
** AObject
** File description:
** Interface
*/

#pragma once
#include <cstddef>

#include "IEntity.hpp"

namespace bbm {
	class AObject : public IEntity {
	public:
		AObject() = default;
		virtual ~AObject() = default;
	};
}
