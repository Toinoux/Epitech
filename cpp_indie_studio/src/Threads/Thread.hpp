/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Thread.hpp
*/

#pragma once
#include <functional>
#include <mutex>
#include <condition_variable>

#include "IDataQueue.hpp"

namespace bbm {
	struct ThreadData {
                std::condition_variable &_condVar;
                std::mutex &_guard;
                IDataQueue<std::function<void()>> &_taskQueue;
        };

	class Thread {
	public:
		Thread() = delete;
		Thread(const ThreadData &data);
		Thread(const Thread &thread);
		~Thread();
		Thread &operator=(Thread &thread) = delete;

	public:
		void work();
		inline std::condition_variable &getCondVar() const;
		inline IDataQueue<std::function<void()>> &getTaskQueue() const;
		inline bool getRun() const;

	private:
		std::condition_variable &_condVar;
		std::mutex &_guard;
		IDataQueue<std::function<void()>> &_taskQueue;
		bool _isRunning;
	};
}

std::condition_variable &bbm::Thread::getCondVar() const
{
	return _condVar;
}

bbm::IDataQueue<std::function<void()>> &bbm::Thread::getTaskQueue() const
{
	return _taskQueue;
}

bool bbm::Thread::getRun() const
{
	return _isRunning;
}
