#include "SJF_Scheduler.h"
#include <vector>
#include "Process.h"
#include <iostream>
#include "GanttChart.h"
#include <cassert>
#include <iostream>

using namespace std;

SJF_Scheduler::SJF_Scheduler()
{
}

SJF_Scheduler::~SJF_Scheduler()
{
}

void SJF_Scheduler::run(std::vector<Process> waitingQ) const
{
	GanttChart ganttChart;							
	vector<Process> sortedProcesses;					
	float time = 0;
	assert(!waitingQ.empty() && "Waiting queue is empty");
	assert(time >= 0 && "Time must be non-negative");
	
	// Sort the processes based on burst time
	while (!waitingQ.empty()) {
		auto it = min_element(
			waitingQ.begin(),
			waitingQ.end(),
			[](Process& a, Process& b) {
				return a.getBurstTime() < b.getBurstTime();
			}
		);
		sortedProcesses.push_back(*it);
		waitingQ.erase(it);
	}
	

	
}

float SJF_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
{
	// Calculate the average turnaround time
	float totalTurnaroundTime = 0.0f;
	for (const auto& process : processes) {
		totalTurnaroundTime += process.getTurnaroundTime();
	}
	return totalTurnaroundTime /= processes.size();
}

float SJF_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
{
	// Calculate the average waiting time
	float totalWaitingTime = 0.0f;
	for (const auto& process : processes) {
		totalWaitingTime += process.getWaitingTime();
	}
	return totalWaitingTime /= processes.size();
}
