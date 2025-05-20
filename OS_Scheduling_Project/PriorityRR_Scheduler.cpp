#include "PriorityRR_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"
#include <deque>

using namespace std;

void PriorityRR_Scheduler::run(std::vector<Process> waitingQ) const
{
	GanttChart ganttChart;
	float time = 0;
	assert(!waitingQ.empty() && "Waiting queue is empty");
	assert(time >= 0 && "Time must be non-negative");

	std::deque<Process> sortedProcessQ;	

	// Sort the processes based on priority
	while (!waitingQ.empty()) {
		auto it = min_element(
			waitingQ.begin(),
			waitingQ.end(),
			[](Process& a, Process& b) {
				assert(a.getPriority() >= 0 && b.getPriority() >= 0 && "Priority must be non-negative"); //Assert that priority is non-negative
				return a.getPriority() > b.getPriority();
			}
		);
		sortedProcessQ.push_back(*it);
		waitingQ.erase(it);
	}

	// Run the processes in round-robin fashion
	while (!sortedProcessQ.empty()) {
		// take the front process
		Process p = sortedProcessQ.front();
		sortedProcessQ.pop_front();
		assert(time >= 0 && "Time must be non-negative");

		if (p.getRemainingTime() > this->tQuantum) {
			// Process will run for the time quantum
			p.setStart(time);							// Set start time
			p.setEnd(time + this->tQuantum);			// Set end time
			time += this->tQuantum;
			p.remainingTimeUpdate(this->tQuantum);

			//calculate waiting time and turnaround time
			p.calculateWaitingTime(time);
			p.calculateTurnaroundTime(time);
			ganttChart.stamp(p);
			sortedProcessQ.push_front(p);				// Add the process back to the queue

			// Print the process details
			cout << "Running Process PID: " << p.getPID() << endl;
			cout << "Start Time: " << p.getStart() << endl;
			cout << "End Time: " << p.getEnd() << endl;
			cout << "Waiting Time: " << p.getWaitingTime() << endl;
			cout << "Turnaround Time: " << p.getTurnaroundTime() << "\n" << endl;
		}
		else {
			// Process will finish its execution
			p.setStart(time); // Set start time
			p.setEnd(time + p.getRemainingTime());	// Set end time
			time += p.getRemainingTime();
			p.remainingTimeUpdate(0);

			//calculate waiting time and turnaround time
			p.calculateWaitingTime(time);
			p.calculateTurnaroundTime(time);
			ganttChart.stamp(p);

			// Print the process details
			cout << "Running Process PID: " << p.getPID() << endl;
			cout << "Start Time: " << p.getStart() << endl;
			cout << "End Time: " << p.getEnd() << endl;
			cout << "Waiting Time: " << p.getWaitingTime() << endl;
			cout << "Turnaround Time: " << p.getTurnaroundTime() << "\n" << endl;
		}

	}
	std::cout << "===================== PRIORITY ROUND ROBIN ALGORITHM =====================\n";
	ganttChart.print();
}

float PriorityRR_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
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

float PriorityRR_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
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
