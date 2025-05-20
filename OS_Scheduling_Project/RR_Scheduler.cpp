#include "RR_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"
#include <deque>

using namespace std;

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
	
	std::deque<Process> processQueue(waitingQ.begin(), waitingQ.end());	// Create a deque to hold the processes in the waiting queue

	// Run the processes in round-robin fashion
    while (!processQueue.empty()) {
		assert(time >= 0 && "Time must be non-negative");

        // take the front process
        Process p = processQueue.front();
        processQueue.pop_front();

		if (p.getRemainingTime() > this->tQuantum) {
			// Process will run for the time quantum
			p.setStart(time);					// Set start time
			p.setEnd(time + this->tQuantum);			// Set end time
			time += this->tQuantum;
			p.remainingTimeUpdate(this->tQuantum);

			//calculate waiting time and turnaround time
			p.calculateWaitingTime(time);
			p.calculateTurnaroundTime(time);
			ganttChart.stamp(p);
			processQueue.push_back(p);			// Add the process back to the queue

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
	std::cout << "===================== ROUND ROBIN ALGORITHM =====================\n";
	ganttChart.print();
}

float RR_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
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

float RR_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
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
