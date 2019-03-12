/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** IDataQueue.hpp
*/

#pragma once

namespace bbm {
	template <typename T>
	class IDataQueue {
	public:
		virtual ~IDataQueue() = default;
		virtual void push(const T &value) = 0;
		virtual void pop() = 0;
		virtual bool empty() = 0;
		virtual size_t size() = 0;
		virtual const T &front() = 0;
	};
}
