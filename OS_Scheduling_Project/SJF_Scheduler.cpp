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
	cout << "===================== SJF ALGORITHM =====================\n";
	ganttChart.print();
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
