#include "RR_Scheduler.h"
#include <iostream>
#include <vector>
#include "Process.h"
#include <cassert>
#include "GanttChart.h"
#include <deque>

using namespace std;

/**
 * @brief Constructor for RR_Scheduler class.
 *
 * Initializes the time quantum for Round Robin scheduling.
 *
 * @param tQ Time quantum for Round Robin scheduling.
 */
RR_Scheduler::RR_Scheduler(float tQ)
{
    this->tQuantum = tQ;
}

/**
 * @brief Destructor for RR_Scheduler class.
 */
RR_Scheduler::~RR_Scheduler()
{
    // Destructor implementation, if needed.
}

/**
 * @brief Executes the Round Robin scheduling algorithm.
 *
 * This method runs the Round Robin scheduling algorithm on the provided waiting queue
 * of processes, using the specified time quantum.
 *
 * @param waitingQ Vector of processes in the waiting queue.
 */
void RR_Scheduler::run(std::vector<Process> waitingQ) const
{
    GanttChart ganttChart; // Gantt chart to visualize scheduling

    float time = 0; // Current time
    assert(!waitingQ.empty() && "Waiting queue is empty");

    std::deque<Process> processQueue(waitingQ.begin(), waitingQ.end()); // Deque to hold processes

    // Run the processes in round-robin fashion
    while (!processQueue.empty()) {
        assert(time >= 0 && "Time must be non-negative");

        // Take the front process
        Process p = processQueue.front();
        processQueue.pop_front();

        if (p.getRemainingTime() > this->tQuantum) {
            // Process runs for the time quantum
            p.setStart(time); // Set start time
            p.setEnd(time + this->tQuantum); // Set end time
            time += this->tQuantum;
            p.remainingTimeUpdate(this->tQuantum);

            // Calculate waiting time and turnaround time
            p.calculateWaitingTime(time);
            p.calculateTurnaroundTime(time);
            ganttChart.stamp(p);
            processQueue.push_back(p); // Add process back to queue

            // Print process details
            cout << "Running Process PID: " << p.getPID() << endl;
            cout << "Start Time: " << p.getStart() << endl;
            cout << "End Time: " << p.getEnd() << endl;
            cout << "Waiting Time: " << p.getWaitingTime() << endl;
            cout << "Turnaround Time: " << p.getTurnaroundTime() << "\n" << endl;
        }
        else {
            // Process finishes execution
            p.setStart(time); // Set start time
            p.setEnd(time + p.getRemainingTime()); // Set end time
            time += p.getRemainingTime();
            p.remainingTimeUpdate(0);

            // Calculate waiting time and turnaround time
            p.calculateWaitingTime(time);
            p.calculateTurnaroundTime(time);
            ganttChart.stamp(p);

            // Print process details
            cout << "Running Process PID: " << p.getPID() << endl;
            cout << "Start Time: " << p.getStart() << endl;
            cout << "End Time: " << p.getEnd() << endl;
            cout << "Waiting Time: " << p.getWaitingTime() << endl;
            cout << "Turnaround Time: " << p.getTurnaroundTime() << "\n" << endl;
        }
    }

    // Print Gantt chart for visualization
    std::cout << "===================== ROUND ROBIN ALGORITHM =====================\n";
    ganttChart.print();
}

/**
 * @brief Calculates the average turnaround time for a list of processes.
 *
 * @param processes Vector of processes for which average turnaround time is calculated.
 * @return Average turnaround time.
 */
float RR_Scheduler::getAverageTurnaroundTime(std::vector<Process> processes) const
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
float RR_Scheduler::getAverageWaitingTime(std::vector<Process> processes) const
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
