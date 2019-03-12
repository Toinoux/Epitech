//
// EPITECH PROJECT, 2018
// AWall
// File description:
// Abstract
//

#pragma once
#include "Object/AObject.hpp"

namespace bbm {
	class AWall : public AObject {
	public:
		AWall(bool isDest, bool isWarp);
		virtual ~AWall() = default;

	protected:
		bool _isDestroy;
		bool _isDestroyable;
		bool _isWarp;
	};
}
