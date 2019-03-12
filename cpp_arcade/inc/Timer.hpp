//
// EPITECH PROJECT, 2018
// Timer
// File description:
// Timer for fps
//

#pragma once

#include <ctime>

class Timer {
private:
	unsigned long startTime;
public:
	void start() {
		startTime = clock();
	}

	unsigned long elapsedTime() {
		return ((unsigned long) clock() - startTime) / CLOCKS_PER_SEC;
	}

	bool isTimeout(unsigned long seconds) {
		return seconds >= elapsedTime();
	}
};
