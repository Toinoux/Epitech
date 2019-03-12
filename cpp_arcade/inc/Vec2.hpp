/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Vec2 custom class
*/

#pragma once

#include <vector>

namespace arc {
	template <typename T>
	class Vec2 {
	public:
		Vec2(T _x, T _y)
			: x(_x), y(_y)
			{}

		T x;
		T y;
	};
}
