#pragma once
#include <vector>
#include "Process.h"
#include <iostream>

class PriorityRR_Scheduler
{
public:
	PriorityRR_Scheduler(float tQ) { this->tQuantum = tQ; };
	~PriorityRR_Scheduler() {};

	void run(std::vector<Process> waitingQ)							const;
	float getAverageTurnaroundTime(std::vector<Process> processes)	const;
	float getAverageWaitingTime(std::vector<Process> processes)		const;
private:
	float tQuantum;														// Time quantum for Round Robin scheduling
};
