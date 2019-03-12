//
// EPITECH PROJECT, 2018
// Timer
// File description:
// Timer
//

#pragma once
#include <ctime>
#include <chrono>

namespace bbm {
	class Timer {
	public:
		Timer();
		~Timer();

	public:
		void resetClock();
		bool elapsedMilliSecond(int milli);
		bool elapsedSecond(int sec);

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> _startClock;
	};
}
