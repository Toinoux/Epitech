/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** Thread.cpp
*/

#include <functional>

#include "Thread.hpp"

bbm::Thread::Thread(const ThreadData &data) : _condVar(data._condVar),
					      _guard(data._guard),
					      _taskQueue(data._taskQueue),
					      _isRunning(false)
{}

bbm::Thread::Thread(const Thread &thread) : _condVar(thread.getCondVar()),
					    _guard(thread._guard),
					    _taskQueue(thread.getTaskQueue())
{}

bbm::Thread::~Thread()
{}

void bbm::Thread::work()
{
	std::function<void()> task;

	while (true) {
		{
			std::unique_lock<std::mutex> lock(_guard);
			_condVar.wait(lock, [&]{ return !_taskQueue.empty(); });
			_isRunning = true;
			task = _taskQueue.front();
			_taskQueue.pop();
		}
		task();
		_isRunning = false;
	}
}
