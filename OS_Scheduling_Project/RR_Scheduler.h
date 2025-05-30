#pragma once
#include <vector>
#include "Process.h"
#include <iostream>
#include <deque>

class RR_Scheduler
{
public:
	RR_Scheduler(float tQ);
	~RR_Scheduler();

	void run(std::vector<Process> waitingQ)							const;
	float getAverageTurnaroundTime(std::vector<Process> processes)	const;
	float getAverageWaitingTime(std::vector<Process> processes)		const;

	//getters
	float getTimeQuantum() const { return tQuantum; } // Getter for time quantum

private:
	float tQuantum;														// Time quantum for Round Robin scheduling
};
