#pragma once
#include <vector>
#include "Process.h"
#include <iostream>

class FCFS_Scheduler
{
public:
	FCFS_Scheduler();
	~FCFS_Scheduler();
	void run(std::vector<Process> waitingQ) const;
	
private:
};

