#include "RR_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"

RR_Scheduler::RR_Scheduler(float tQ=20)
{
	this->tQuantum= tQ; // Initialize the time this->tQuantum for Round Robin scheduling
}

RR_Scheduler::~RR_Scheduler()
{
}

void RR_Scheduler::run(std::vector<Process> waitingQ) const
{
	GanttChart ganttChart;
	std::vector<Process> sortedProcesses;
	float time = 0;
	assert(!waitingQ.empty() && "Waiting queue is empty");
	assert(time >= 0 && "Time must be non-negative");
	// Run the processes in round-robin fashion
	while (!waitingQ.empty()) {
		for (auto it = waitingQ.begin(); it != waitingQ.end();) {
			if (it->getBurstTime() > this->tQuantum) {
				it->setStart(time);
				it->setEnd(time + this->tQuantum);
				time += this->tQuantum;
				it->remainingTimeUpdate(it->getBurstTime() - this->tQuantum);
				ganttChart.stamp(*it);
				std::cout << "Running Process PID: " << it->getPID() << std::endl;
				std::cout << "Start Time: " << it->getStart() << std::endl;
				std::cout << "End Time: " << it->getEnd() << std::endl;
			}
			else {
				it->setStart(time);
				it->setEnd(time + it->getBurstTime());
				time += it->getBurstTime();
				ganttChart.stamp(*it);
				std::cout << "Running Process PID: " << it->getPID() << std::endl;
				std::cout << "Start Time: " << it->getStart() << std::endl;
				std::cout << "End Time: " << it->getEnd() << std::endl;
				waitingQ.erase(it);
			}
			++it;
		}
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
