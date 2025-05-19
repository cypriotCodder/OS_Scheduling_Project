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
	int getStart() const { return t_start; }
	int getEnd() const { return t_end; }
	

	//setters
	void remainingUpdate(int delta);
	void setStart(int t_start) { this->t_start = t_start; }
	void setEnd(int t_end) { this->t_end = t_end; }

private:
	int pid;
	int arrival_time;
	int burst_time;
	int priority;
	int remaining_time;

	int t_start;
	int t_end;
};


