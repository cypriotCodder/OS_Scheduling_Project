#pragma once
#include <vector>
#include "Process.h"
#include <iostream>
#include "GanttChart.h"

class FCFS_Scheduler
{
public:
	FCFS_Scheduler();
	~FCFS_Scheduler();
	void run(std::vector<Process> waitingQ) const;

private:
};

