#include "Priority_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"

using namespace std;

Priority_Scheduler::Priority_Scheduler()
{
}

Priority_Scheduler::~Priority_Scheduler()
{
}

void Priority_Scheduler::run(std::vector<Process> waitingQ) const
{
	GanttChart ganttChart;							
	vector<Process> sortedProcesses;
	float time = 0;
	assert(!waitingQ.empty() && "Waiting queue is empty");
	assert(time >= 0 && "Time must be non-negative");

	// Sort the processes based on priority
	while (!waitingQ.empty()) {
		auto it = min_element(
			waitingQ.begin(),
			waitingQ.end(),
			[](Process& a, Process& b) {
				return a.getPriority() > b.getPriority();
			}
		);
		sortedProcesses.push_back(*it);
		waitingQ.erase(it);
	}

	// Run the processes in sorted order
	for (auto& currentProcess : sortedProcesses) {
		currentProcess.setStart(time);									// Set start time to 0 for simplicity
		currentProcess.setEnd(time + currentProcess.getBurstTime());	// Set end time to burst time
		time += currentProcess.getBurstTime();							// Increment the time by the burst time of the process
		// Calculate waiting time and turnaround time
		currentProcess.calculateWaitingTime(time);
		currentProcess.calculateTurnaroundTime(time);
		// Add the process to the Gantt chart
		ganttChart.stamp(currentProcess);
		// Print the process details
		cout << "Running Process PID: " << currentProcess.getPID() << endl;
		cout << "Start Time: " << currentProcess.getStart() << endl;
		cout << "End Time: " << currentProcess.getEnd() << endl;
		cout << "Waiting Time: " << currentProcess.getWaitingTime() << endl;
		cout << "Turnaround Time: " << currentProcess.getTurnaroundTime() << "\n" << endl;
	}

	cout << "===================== PRIORITY ALGORITHM =====================\n";
	ganttChart.print();
}

float Priority_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
{
	return 0.0f;
}

float Priority_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
{
	return 0.0f;
}
