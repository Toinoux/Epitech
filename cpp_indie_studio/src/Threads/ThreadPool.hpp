/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** ThreadPool.hpp
*/

#pragma once
#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <memory>
#include <functional>

#include "Core/ICore.hpp"
#include "IDataQueue.hpp"
#include "Thread.hpp"

namespace bbm {

	static const int DEFAULT_THREADS = std::thread::hardware_concurrency();

	class ThreadPool {
	public:
		ThreadPool();
		ThreadPool(const ThreadPool &tp) = delete;
		~ThreadPool();
		ThreadPool &operator=(ThreadPool &tp) = delete;

	public:
		void addTask(const ICore &core);
		static void doTask(const ICore &core);

	private:
		void _createThreads(size_t nbThreads);
		void _manageThreads(size_t reqThreads);
		size_t _getAvailableThreads();

		std::condition_variable _condVar;
		std::mutex _guard;
		std::vector<std::unique_ptr<Thread>> _threadList;
		std::unique_ptr<IDataQueue<std::function<void()>>> _taskQueue;
		size_t _runningThreads;
	};
}
