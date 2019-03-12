/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** DataQueue
*/

#pragma once
#include <mutex>
#include <queue>

#include "IDataQueue.hpp"

namespace bbm {
	template <typename T>
	class DataQueue : public IDataQueue<T> {
	public:
		DataQueue();
		DataQueue(const DataQueue<T> &dataQueue) = delete;
		~DataQueue() = default;
		DataQueue<T> &operator=(DataQueue<T> &dataQueue) = delete;

	public:
		void push(const T &value) final;
		void pop() final;
		bool empty() final;
		size_t size() final;
		const T &front() final;

	protected:
		std::mutex _push;
		std::mutex _pop;
		std::mutex _empty;
		std::mutex _size;
		std::mutex _front;
		std::queue<T> _dataQueue;
	};
}

template<typename T>
bbm::DataQueue<T>::DataQueue() : _push(), _pop(), _empty(), _size(), _front(), _dataQueue()
{
}

template<typename T>
void bbm::DataQueue<T>::push(const T &value)
{
	std::unique_lock<std::mutex> uniqueLock(_push);
	_dataQueue.push(value);
}

template<typename T>
void bbm::DataQueue<T>::pop()
{
	std::unique_lock<std::mutex> uniqueLock(_pop);
	_dataQueue.pop();
}

template<typename T>
bool bbm::DataQueue<T>::empty()
{
	std::unique_lock<std::mutex> uniqueLock(_empty);
	return _dataQueue.empty();
}

template<typename T>
size_t bbm::DataQueue<T>::size()
{
	std::unique_lock<std::mutex> uniqueLock(_size);
	return _dataQueue.size();
}

template<typename T>
const T &bbm::DataQueue<T>::front()
{
	std::unique_lock<std::mutex> uniqueLock(_front);
	return _dataQueue.front();
};
