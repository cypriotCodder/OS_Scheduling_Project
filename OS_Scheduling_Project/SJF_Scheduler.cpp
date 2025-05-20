#include "SJF_Scheduler.h"
#include <vector>
#include "Process.h"
#include <iostream>
#include "GanttChart.h"
#include <cassert>

using namespace std;

/**
 * @brief Default constructor for SJF_Scheduler class.
 */
SJF_Scheduler::SJF_Scheduler()
{
}

/**
 * @brief Destructor for SJF_Scheduler class.
 */
SJF_Scheduler::~SJF_Scheduler()
{
}

/**
 * @brief Executes the Shortest Job First (SJF) scheduling algorithm.
 *
 * This method runs the SJF scheduling algorithm on the provided waiting queue
 * of processes. It sorts processes based on their burst times, simulates each
 * process's execution, calculates waiting and turnaround times, and generates
 * a Gantt chart for visualization.
 *
 * @param waitingQ Vector of processes in the waiting queue.
 */
void SJF_Scheduler::run(std::vector<Process> waitingQ) const
{
    GanttChart ganttChart;                  // Create a Gantt chart object
    vector<Process> sortedProcesses;        // Vector to hold processes sorted by burst time
    float time = 0;                         // Current time

    assert(!waitingQ.empty() && "Waiting queue is empty");

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
        assert(time >= 0 && "Time must be non-negative");

        // Simulate the process execution
        currentProcess.setStart(time);                                  // Set start time
        currentProcess.setEnd(time + currentProcess.getBurstTime());    // Set end time
        time += currentProcess.getBurstTime();                          // Increment the time by the burst time of the process

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
    cout << "===================== SJF ALGORITHM =====================\n";
    ganttChart.print();
}

/**
 * @brief Calculates the average turnaround time for a list of processes.
 *
 * @param processes Vector of processes for which average turnaround time is calculated.
 * @return Average turnaround time.
 */
float SJF_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
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
float SJF_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
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
