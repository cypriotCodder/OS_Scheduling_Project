#pragma once
#include <vector>
#include "Process.h"
#include <iostream>

class SJF_Scheduler
{
public:
	SJF_Scheduler();
	~SJF_Scheduler();

	void run(std::vector<Process> waitingQ) const;
	float getAverageTurnaroundTime(std::vector<Process> processes)	const;
	float getAverageWaitingTime(std::vector<Process> processes)		const;

private:

};

