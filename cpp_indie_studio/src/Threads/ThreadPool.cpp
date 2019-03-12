/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** ThreadPool.cpp
*/

#include <functional>
#include <iostream>

#include "DataQueue.hpp"
#include "ThreadPool.hpp"
#include "Thread.hpp"

bbm::ThreadPool::ThreadPool() : _condVar(), _guard(),
				_threadList(), _taskQueue(),
				_runningThreads(0)
{
	std::cout << "Create pool" << std::endl;
	_taskQueue = std::make_unique<DataQueue<std::function<void()>>>();
	std::cout << "Create thread" << std::endl;
	_createThreads(DEFAULT_THREADS);
	std::cout << "Pool Created" << std::endl;
}

bbm::ThreadPool::~ThreadPool()
{}

void bbm::ThreadPool::addTask(const bbm::ICore &core)
{
	auto task = std::bind(&bbm::ThreadPool::doTask, std::ref(core));
	{
		std::unique_lock<std::mutex> lock(_guard);
		_taskQueue->push(task);
	}
	_manageThreads(1);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void bbm::ThreadPool::doTask(const bbm::ICore &core)
{
	const_cast<bbm::ICore&>(core).run();
}

void bbm::ThreadPool::_manageThreads(size_t reqThreads)
{
	auto availableThreads = _getAvailableThreads();

	if (reqThreads > availableThreads) {
		reqThreads = reqThreads - availableThreads;
		_createThreads(reqThreads);
	}
	_condVar.notify_all();
}

void bbm::ThreadPool::_createThreads(size_t nbThreads)
{
	for (size_t it = 0; it < nbThreads; it++) {
		ThreadData data = {
			std::ref(_condVar),
			std::ref(_guard),
			*_taskQueue
		};
		_threadList.push_back(std::make_unique<Thread>(data));
		std::thread t(std::bind(&bbm::Thread::work,
					(&(*_threadList.back()))));
		t.detach();
	}
}

size_t bbm::ThreadPool::_getAvailableThreads()
{
	size_t availableThreads = 0;

	for (const auto &it : _threadList) {
		if (!it->getRun())
			availableThreads++;
	}
	return availableThreads;
}
