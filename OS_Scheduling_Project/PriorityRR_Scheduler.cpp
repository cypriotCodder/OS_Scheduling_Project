#include "PriorityRR_Scheduler.h"
#include <iostream>
#include <vector> 
#include "Process.h"
#include <cassert>
#include "GanttChart.h"
#include <deque>

using namespace std;

/**
 * @brief Runs the Priority Round Robin scheduling algorithm.
 *
 * This method executes the Priority Round Robin scheduling algorithm
 * on the provided waiting queue of processes.
 *
 * @param waitingQ Vector of processes in the waiting queue.
 */
void PriorityRR_Scheduler::run(std::vector<Process> waitingQ) const
{
    GanttChart ganttChart; // Gantt chart to visualize scheduling

    float time = 0; // Current time
    assert(!waitingQ.empty() && "Waiting queue is empty");
    assert(time >= 0 && "Time must be non-negative");

    deque<Process> sortedProcessQ; // Deque to hold sorted processes by priority
	vector<Process> tempList; // hold for stats

    // Sort the processes based on priority
    while (!waitingQ.empty()) {
        auto it = min_element(
            waitingQ.begin(),
            waitingQ.end(),
            [](Process& a, Process& b) {
                assert(a.getPriority() >= 0 && b.getPriority() >= 0 && "Priority must be non-negative");
                return a.getPriority() > b.getPriority();
            }
        );
        sortedProcessQ.push_back(*it);
        waitingQ.erase(it);
    }

    // Run the processes in round-robin fashion
    while (!sortedProcessQ.empty()) {
        Process p = sortedProcessQ.front();
        sortedProcessQ.pop_front();
        assert(time >= 0 && "Time must be non-negative");

        if (p.getRemainingTime() > this->tQuantum) {
            // Process runs for the time quantum
            p.setStart(time);
            p.setEnd(time + this->tQuantum);
            time += this->tQuantum;
            p.remainingTimeUpdate(this->tQuantum);

            // Calculate waiting time and turnaround time
            p.calculateWaitingTime(time);
            p.calculateTurnaroundTime(time);
            ganttChart.stamp(p);
            sortedProcessQ.push_front(p); // Add process back to queue

            // Print process details
            /*cout << "Running Process PID: " << p.getPID() << endl;
            cout << "Start Time: " << p.getStart() << endl;
            cout << "End Time: " << p.getEnd() << endl;
            cout << "Waiting Time: " << p.getWaitingTime() << endl;
            cout << "Turnaround Time: " << p.getTurnaroundTime() << "\n" << endl;*/
        }
        else {
            // Process finishes execution
            p.setStart(time);
            p.setEnd(time + p.getRemainingTime());
            time += p.getRemainingTime();
            p.remainingTimeUpdate(0);

            // Calculate waiting time and turnaround time
            p.calculateWaitingTime(time);
            p.calculateTurnaroundTime(time);
            ganttChart.stamp(p);
            tempList.push_back(p); // Add process to tempList for stats

            // Print process details
            /*cout << "\nRunning Process PID: " << p.getPID() << endl;
            cout << "Start Time: " << p.getStart() << endl;
            cout << "End Time: " << p.getEnd() << endl;
            cout << "Waiting Time: " << p.getWaitingTime() << endl;
            cout << "Turnaround Time: " << p.getTurnaroundTime() << "\n" << endl;*/
        }
    }

    // Print Gantt chart for visualization
    ganttChart.print();
	std::cout << "STATISTICS:\n";
	std::cout << "Average Turnaround Time: " << getAverageTurnaroundTime(tempList) << "ms\n";
	std::cout << "Average Waiting Time: " << getAverageWaitingTime(tempList) << "ms\n\n";

	cout << "===================== END OF PRIORITY ROUND ROBIN ALGORITHM =====================\n\n";
}

/**
 * @brief Calculates the average turnaround time for a list of processes.
 *
 * @param processes Vector of processes for which average turnaround time is calculated.
 * @return Average turnaround time.
 */
float PriorityRR_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
{
    float totalTurnaroundTime = 0.0f;
    assert(!processes.empty() && "Process list is empty");
    assert(totalTurnaroundTime >= 0 && "Total turnaround time must be non-negative");

    // Calculate total turnaround time
    for (const auto& process : processes) {
        totalTurnaroundTime += process.getTurnaroundTime();
    }

    return totalTurnaroundTime / processes.size(); // Calculate and return average
}

/**
 * @brief Calculates the average waiting time for a list of processes.
 *
 * @param processes Vector of processes for which average waiting time is calculated.
 * @return Average waiting time.
 */
float PriorityRR_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
{
    float totalWaitingTime = 0.0f;
    assert(!processes.empty() && "Process list is empty");
    assert(totalWaitingTime >= 0 && "Total waiting time must be non-negative");

    // Calculate total waiting time
    for (const auto& process : processes) {
        totalWaitingTime += process.getWaitingTime();
    }
    return totalWaitingTime / processes.size(); // Calculate and return average
}
