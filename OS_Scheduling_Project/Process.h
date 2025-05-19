#pragma once

class Process
{
public:
	Process(int pid, int arrivalTime, int burstTime, int priority=0);
	~Process();

	//getters
	int getPID()			const { return pid; }
	int getArrivalTime()	const { return arrival_time; }
	int getBurstTime()		const { return burst_time; }
	int getRemainingTime()	const { return remaining_time; }
	int getWaitingTime()	const { return waiting_time; }
	int getTurnaroundTime()	const { return turnaround_time; }
	int getPriority()		const { return priority; }
	int getStart()			const { return t_start; }
	int getEnd()			const { return t_end; }
	

	//setters
	void remainingTimeUpdate(int delta);
	void setStart(int t_start) { this->t_start = t_start; }
	void setEnd(int t_end) { this->t_end = t_end; }
	void setWaitingTime(int waiting_time) { this->waiting_time = waiting_time; }
	void setTurnaroundTime(int turnaround_time) { this->turnaround_time = turnaround_time; }

	//calculating waiting time and turnaround time
	void calculateWaitingTime(int current_time);
	void calculateTurnaroundTime(int current_time);

private:
	int pid;
	int priority;
	float arrival_time;
	float burst_time;
	float remaining_time;
	float waiting_time;
	float turnaround_time;

	float t_start;
	float t_end;
};


