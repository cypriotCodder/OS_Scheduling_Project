#pragma once
#include <vector>
#include "Process.h"
#include <iostream>

class Priority_Scheduling
{
public:
	Priority_Scheduling();
	~Priority_Scheduling();
	void run(std::vector<Process> waitingQ) const;
	float getAverageTurnaroundTime(std::vector<Process> processes)	const;
	float getAverageWaitingTime(std::vector<Process> processes)		const;
private:

};

