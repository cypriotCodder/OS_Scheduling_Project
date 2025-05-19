#include "Priority_Scheduling.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"

using namespace std;

Priority_Scheduling::Priority_Scheduling()
{
}

Priority_Scheduling::~Priority_Scheduling()
{
}

void Priority_Scheduling::run(std::vector<Process> waitingQ) const
{
	GanttChart ganttChart;							
	float time = 0;
	assert(!waitingQ.empty() && "Waiting queue is empty");
	assert(time >= 0 && "Time must be non-negative");

	// Sort the processes based on priority
	while (!waitingQ.empty()) {
		auto it = min_element(
			waitingQ.begin(),
			waitingQ.end(),
			[](Process& a, Process& b) {
				return a.getPriority() < b.getPriority();
			}
		);
	}
}

float Priority_Scheduling::getAverageTurnaroundTime(std::vector<Process> processes) const
{
	return 0.0f;
}

float Priority_Scheduling::getAverageWaitingTime(std::vector<Process> processes) const
{
	return 0.0f;
}
