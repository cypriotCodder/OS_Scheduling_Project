#include "FCFS_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"

using namespace std;

FCFS_Scheduler::FCFS_Scheduler()
{
}

FCFS_Scheduler::~FCFS_Scheduler()
{
}

void FCFS_Scheduler::run(vector<Process> waitingQ) const
{
	GanttChart ganttChart;							// Create a Gantt chart object
	float time = 0;
	assert(!waitingQ.empty() && "Waiting queue is empty");
	assert(time >= 0 && "Time must be non-negative");

	while (!waitingQ.empty()) {
		Process currentProcess = waitingQ.front();	// Get the first process in the queue
		waitingQ.erase(waitingQ.begin());			// Remove it from the queue
		
		// Simulate the process execution
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
	// Print the Gantt chart
	cout << "===================== FCFS ALGORITHM =====================\n";
	ganttChart.print();
}

float FCFS_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
{
	// Calculate the average turnaround time
	float totalTurnaroundTime = 0.0f;

	assert(!processes.empty() && "Process list is empty");
	assert(totalTurnaroundTime >= 0 && "Total turnaround time must be non-negative");
	for (const auto& process : processes) {
		totalTurnaroundTime += process.getTurnaroundTime();
	}
	return totalTurnaroundTime /= processes.size();
}

float FCFS_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
{
	// Calculate the average waiting time
	float totalWaitingTime = 0.0f;

	assert(!processes.empty() && "Process list is empty");
	assert(totalWaitingTime >= 0 && "Total turnaround time must be non-negative");
	for (const auto& process : processes) {
		totalWaitingTime += process.getWaitingTime();
	}
	return totalWaitingTime /= processes.size();
}




