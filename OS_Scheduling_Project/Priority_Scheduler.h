#pragma once
#include <vector>
#include "Process.h"
#include <iostream>

class Priority_Scheduler
{
public:
	Priority_Scheduler();
	~Priority_Scheduler();
	void run(std::vector<Process> waitingQ)							const;
	float getAverageTurnaroundTime(std::vector<Process> processes)	const;
	float getAverageWaitingTime(std::vector<Process> processes)		const;
private:

};

