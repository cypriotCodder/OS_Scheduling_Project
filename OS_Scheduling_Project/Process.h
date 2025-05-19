#pragma once

class Process
{
public:
	Process(int pid, int arrivalTime, int burstTime, int remainingTime, int priority=0);
	~Process();

	//getters
	int getPID() const { return pid; }
	int getArrivalTime() const { return arrival_time; }
	int getBurstTime() const { return burst_time; }
	int getRemainingTime() const { return remaining_time; }
	int getPriority() const { return priority; }
	

	//setters
	void remainingUpdate(int delta);


private:
	int pid;
	int arrival_time;
	int burst_time;
	int priority;
	int remaining_time;
};

Process::Process(int pid, int arrivalTime, int burstTime, int remainingTime, int priority = 0)
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

inline void Process::remainingUpdate(int delta)
{
}
