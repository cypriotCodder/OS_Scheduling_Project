#pragma once
#include <vector>
#include "Process.h"
#include "GanttChart.h"
#include "FCFS_Scheduler.h"


class Scheduler
{
public:
	Scheduler(std::vector<Process> processes);
	~Scheduler();

	void run()							const;
	void printGanttChart()				const;
	void printProcesses()				const;
	void printAverageTurnaroundTime()	const;
	void printAverageWaitingTime()		const;
	void printAverageResponseTime()		const;


protected:
	std::vector<Process> readyQueue;	// Pointer to the process queue
	std::vector<Process> waitingQueue;	// Pointer to the waiting queue
	std::vector<Process> finishedQueue;	// Pointer to the finished queue
	GanttChart ganttChart;				// Gantt chart object

	FCFS_Scheduler fcfs_Scheduler;				// FCFS scheduler object
	//SJF_Scheduler sjfScheduler;				// SJF scheduler object
	//RR_Scheduler rrScheduler;					// RR scheduler object
	//Priority_Scheduler priorityScheduler;		// Priority scheduler object
	//Priorty_RR_Scheduler priorityRRScheduler; // Priority RR scheduler object
};

