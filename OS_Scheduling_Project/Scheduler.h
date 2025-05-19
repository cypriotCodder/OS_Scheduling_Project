#pragma once
#include <vector>
#include "Process.h"
#include "GanttChart.h"


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


private:
	std::vector<Process> readyQueue;	// Pointer to the process queue
	std::vector<Process> waitingQueue;	// Pointer to the waiting queue
	GanttChart ganttChart;				// Gantt chart object
};

