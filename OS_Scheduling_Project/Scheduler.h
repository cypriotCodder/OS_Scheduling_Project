#pragma once
#include <vector>
#include "Process.h"
#include "FCFS_Scheduler.h"
#include "SJF_Scheduler.h"
#include "Priority_Scheduler.h"
#include "RR_Scheduler.h"
#include "PriorityRR_Scheduler.h"


class Scheduler
{
public:
	Scheduler(std::vector<Process> processes);
	~Scheduler();

	void run()														const;
	void printProcesses()											const;
	void printStats()												const;


protected:
	std::vector<Process> readyQueue;	// Pointer to the process queue
	std::vector<Process> waitingQueue;	// Pointer to the waiting queue
	std::vector<Process> finishedQueue;	// Pointer to the finished queue

	FCFS_Scheduler fcfs_Scheduler;											// FCFS scheduler object
	SJF_Scheduler sjfScheduler;												// SJF scheduler object
	RR_Scheduler rrScheduler = RR_Scheduler(20);							// RR scheduler object
	Priority_Scheduler priorityScheduler;									// Priority scheduler object
	PriorityRR_Scheduler priorityRRScheduler = PriorityRR_Scheduler(20);	// Priority RR scheduler object
};

