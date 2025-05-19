#include "Process.h"

Process::Process(int pid, int arrivalTime, int burstTime, int remainingTime, int priority)
{
	this->pid = pid;
	this->arrival_time = arrivalTime;
	this->burst_time = burstTime;
	this->remaining_time = remainingTime;
	this->priority = priority;
}

Process::~Process()
{
}

void Process::remainingUpdate(int delta)
{
}
