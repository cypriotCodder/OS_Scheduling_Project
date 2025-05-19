#pragma once
#include <vector>
#include "Process.h"

class FCFS_Scheduler
{
public:
	FCFS_Scheduler();
	~FCFS_Scheduler();
	void schedule(std::vector<Process>& processes) const;
	
private:

};

