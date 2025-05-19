#include "FCFS_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"

using namespace std;

FCFS_Scheduler::FCFS_Scheduler()
{
}

FCFS_Scheduler::~FCFS_Scheduler()
{
}

void FCFS_Scheduler::run(vector<Process> waitingQ) const
{
	float time = 0;
	while (!waitingQ.empty()) {
		Process currentProcess = waitingQ.front(); // Get the first process in the queue
		waitingQ.erase(waitingQ.begin()); // Remove it from the queue
		// Simulate the process execution
		
		currentProcess.setStart(time); // Set start time to 0 for simplicity
		currentProcess.setEnd(time + currentProcess.getBurstTime()); // Set end time to burst time
		time += currentProcess.getBurstTime(); // Increment the time by the burst time of the process
		// Print the process details
		cout << "Running Process PID: " << currentProcess.getPID() << endl;
		cout << "Start Time: " << currentProcess.getStart() << endl;
		cout << "End Time: " << currentProcess.getEnd() << endl;
	}
}


