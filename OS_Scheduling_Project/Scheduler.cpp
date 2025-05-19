#include "Scheduler.h"
#include <iostream>
#include <vector>
#include "Process.h"

Scheduler::Scheduler(std::vector<Process> processes)
{
	this->waitingQueue = processes; // Initialize the waiting queue with the processes
}

Scheduler::~Scheduler()
{
}

void Scheduler::run() const
{
}




