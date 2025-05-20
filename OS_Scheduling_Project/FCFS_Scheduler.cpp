#include "FCFS_Scheduler.h"
#include <iostream>
#include <vector>
#include "Process.h"
#include <cassert>
#include "GanttChart.h"

using namespace std;

/**
 * @brief Default constructor for FCFS_Scheduler class.
 */
FCFS_Scheduler::FCFS_Scheduler()
{
}

/**
 * @brief Destructor for FCFS_Scheduler class.
 */
FCFS_Scheduler::~FCFS_Scheduler()
{
}

/**
 * @brief Executes the First Come, First Served (FCFS) scheduling algorithm.
 *
 * This method runs the FCFS scheduling algorithm on the provided waiting queue
 * of processes. It simulates each process's execution, calculates waiting and
 * turnaround times, and generates a Gantt chart for visualization.
 *
 * @param waitingQ Vector of processes in the waiting queue.
 */
void FCFS_Scheduler::run(vector<Process> waitingQ) const
{
    GanttChart ganttChart;                  // Create a Gantt chart object
    float time = 0;                         // Current time
    vector<Process> tempList;    // hold for stats

    assert(!waitingQ.empty() && "Waiting queue is empty");
    assert(time >= 0 && "Time must be non-negative");

    // Process each process in the waiting queue in FCFS order
    while (!waitingQ.empty()) {
        Process currentProcess = waitingQ.front();  // Get the first process in the queue
        waitingQ.erase(waitingQ.begin());           // Remove it from the queue

        // Simulate the process execution
        currentProcess.setStart(time); // Set start time
        currentProcess.setEnd(time + currentProcess.getBurstTime());    // Set end time
        time += currentProcess.getBurstTime();                          // Increment the time by the burst time of the process

        // Calculate waiting time and turnaround time
        currentProcess.calculateWaitingTime(time);
        currentProcess.calculateTurnaroundTime(time);

        // Add the process to the Gantt chart
        ganttChart.stamp(currentProcess);
		tempList.push_back(currentProcess); // Add process to tempList for stats

        // Print the process details
        cout << "Running Process PID: " << currentProcess.getPID() << endl;
        cout << "Start Time: " << currentProcess.getStart() << endl;
        cout << "End Time: " << currentProcess.getEnd() << endl;
        cout << "Waiting Time: " << currentProcess.getWaitingTime() << endl;
        cout << "Turnaround Time: " << currentProcess.getTurnaroundTime() << "\n" << endl;
    }

    // Print the Gantt chart
    ganttChart.print();
    std::cout << "STATISTICS:\n";
    std::cout << "Average Turnaround Time: " << getAverageTurnaroundTime(tempList) << "ms\n";
    std::cout << "Average Waiting Time: " << getAverageWaitingTime(tempList) << "ms\n\n";

	cout << "===================== END OF FCFS ALGORITHM =====================\n";
}

/**
 * @brief Calculates the average turnaround time for a list of processes.
 *
 * @param processes Vector of processes for which average turnaround time is calculated.
 * @return Average turnaround time.
 */
float FCFS_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
{
    // Calculate the average turnaround time
    float totalTurnaroundTime = 0.0f;

    assert(!processes.empty() && "Process list is empty");
    assert(totalTurnaroundTime >= 0 && "Total turnaround time must be non-negative");

    for (const auto& process : processes) {
        totalTurnaroundTime += process.getTurnaroundTime();
    }

    return totalTurnaroundTime / processes.size();
}

/**
 * @brief Calculates the average waiting time for a list of processes.
 *
 * @param processes Vector of processes for which average waiting time is calculated.
 * @return Average waiting time.
 */
float FCFS_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
{
    // Calculate the average waiting time
    float totalWaitingTime = 0.0f;

    assert(!processes.empty() && "Process list is empty");
    assert(totalWaitingTime >= 0 && "Total turnaround time must be non-negative");

    for (const auto& process : processes) {
        totalWaitingTime += process.getWaitingTime();
    }

    return totalWaitingTime / processes.size();
}
