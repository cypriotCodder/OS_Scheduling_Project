#include "RR_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"
#include <deque>

RR_Scheduler::RR_Scheduler(float tQ)
{
	this->tQuantum= tQ; // Initialize the time this->tQuantum for Round Robin scheduling
}

RR_Scheduler::~RR_Scheduler()
{
}

void RR_Scheduler::run(std::vector<Process> waitingQ) const
{
	GanttChart ganttChart;
	float time = 0;
	assert(!waitingQ.empty() && "Waiting queue is empty");
	assert(time >= 0 && "Time must be non-negative");
	
	// Create a deque to hold the processes in the waiting queue
	std::deque<Process> processQueue(waitingQ.begin(), waitingQ.end());

	// Run the processes in round-robin fashion
    while (!processQueue.empty()) {
        // take the front process
        Process p = processQueue.front();
        processQueue.pop_front();

    }
	std::cout << "===================== ROUND ROBIN ALGORITHM =====================\n";
	ganttChart.print();
}

float RR_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
{
	return 0.0f;
}

float RR_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
{
	return 0.0f;
}
