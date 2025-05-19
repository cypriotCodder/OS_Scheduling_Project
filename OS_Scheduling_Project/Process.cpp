#include "Process.h"

Process::Process(int pid, int arrivalTime, int burstTime, int remainingTime, int priority)
{
this->pid = pid;
this->arrival_time = arrivalTime;
this->burst_time = burstTime;
this->remaining_time = remainingTime;
this->priority = priority;

this->t_start = -1; 
this->t_end = -1;   
}

Process::~Process()
{
}

void Process::remainingUpdate(int delta)
{
}
