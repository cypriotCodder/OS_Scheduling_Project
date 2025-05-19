#include "Scheduler.h"
#include <iostream>
#include <vector>
#include "Process.h"
#include "FCFS_Scheduler.h"

Scheduler::Scheduler(std::vector<Process> processes)
{
	this->waitingQueue = processes; // Initialize the waiting queue with the processes
}

Scheduler::~Scheduler()
{
}

void Scheduler::run() const
{
	//Run FCFS Scheduler
	fcfs_Scheduler.run(this->waitingQueue); //TODO: Implement the run function in FCFS_Scheduler
	sjfScheduler.run(this->waitingQueue); //TODO: Implement the run function in SJF_Scheduler
}

void Scheduler::printProcesses() const
{
}

void Scheduler::printStats() const
{
}










