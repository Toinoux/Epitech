//
// EPITECH PROJECT, 2018
// Timer
// File description:
// CPP BBM
//

#include "Timer.hpp"

bbm::Timer::Timer() : _startClock(std::chrono::system_clock::now())
{}

bbm::Timer::~Timer()
{}

void bbm::Timer::resetClock()
{
	_startClock = std::chrono::system_clock::now();
}

bool bbm::Timer::elapsedSecond(int sec)
{
	if (std::chrono::high_resolution_clock::now() >= _startClock +
	    std::chrono::seconds(sec)) {
		resetClock();
		return true;
	}
	else
		return false;
}

bool bbm::Timer::elapsedMilliSecond(int milli)
{
	if (std::chrono::high_resolution_clock::now() >= _startClock +
	    std::chrono::milliseconds(milli)) {
		resetClock();
		return true;
	}
	else
		return false;
}
