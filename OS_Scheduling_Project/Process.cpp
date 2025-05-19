#include "Process.h"

Process::Process(int pid, int arrivalTime, int burstTime, int priority)
{
this->pid = pid;
this->arrival_time = arrivalTime;
this->burst_time = burstTime;
this->remaining_time = burstTime;
this->priority = priority;

this->t_start = -1; 
this->t_end = -1;   
}

Process::~Process()
{
}

void Process::remainingTimeUpdate(int delta)
{
	this->remaining_time -= delta;
}
