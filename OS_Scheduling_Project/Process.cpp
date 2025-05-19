#include "Process.h"
#include <cassert>

Process::Process(int pid, int arrivalTime, int burstTime, int priority)
{
this->pid = pid;
this->arrival_time = arrivalTime;
this->burst_time = burstTime;
this->remaining_time = burstTime;
this->priority = priority;

this->waiting_time = 0;
this->turnaround_time = 0;
this->t_start = -1; 
this->t_end = -1;   
}

Process::~Process()
{
}

void Process::remainingTimeUpdate(int delta)
{
	assert(delta >= 0 && "Delta must be non-negative");
	this->remaining_time -= delta;
}

void Process::calculateWaitingTime(int current_time)
{
	assert(current_time >= 0 && "Current time must be non-negative");

	this->waiting_time = current_time - this->arrival_time - this->burst_time;
}

void Process::calculateTurnaroundTime(int current_time)
{
	assert(current_time >= 0 && "Current time must be non-negative");
	this->turnaround_time = current_time - this->arrival_time;
}
