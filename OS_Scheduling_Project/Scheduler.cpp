#include "Scheduler.h"
#include <iostream>
#include <vector>
#include "Process.h"

/**
 * @brief Constructor for Scheduler class.
 *
 * Initializes the waiting queue with the provided processes.
 *
 * @param processes Vector of processes to initialize the waiting queue.
 */
Scheduler::Scheduler(std::vector<Process> processes)
{
    this->waitingQueue = processes;
}

/**
 * @brief Destructor for Scheduler class.
 */
Scheduler::~Scheduler()
{
    // Destructor implementation, if needed.
}

/**
 * @brief Executes scheduling algorithms.
 *
 * This method sequentially runs several scheduling algorithms on the waiting queue:
 * FCFS, SJF, Priority, Round Robin, and Priority Round Robin.
 */
void Scheduler::run() const
{
    // Run FCFS Scheduler
	std::cout << "===================== FCFS ALGORITHM =====================\n";
    fcfs_Scheduler.run(this->waitingQueue);

    // Run SJF Scheduler
	std::cout << "===================== SJF ALGORITHM =====================\n";
    sjfScheduler.run(this->waitingQueue);

    // Run Priority Scheduler
	std::cout << "===================== PRIORITY ALGORITHM =====================\n";
    priorityScheduler.run(this->waitingQueue);

    // Run Round Robin Scheduler
	std::cout << "===================== ROUND ROBIN ALGORITHM =====================\n";
    rrScheduler.run(this->waitingQueue);

    // Run Priority Round Robin Scheduler
    std::cout << "===================== PRIORITY ROUND ROBIN ALGORITHM =====================\n";
    priorityRRScheduler.run(this->waitingQueue);
}

/**
 * @brief Prints details of all processes.
 *
 * This method prints detailed information about all processes in the waiting queue.
 */
void Scheduler::printProcesses() const
{
    // Implementation for printing processes details, if needed.
}

/**
 * @brief Prints statistical information about scheduling results.
 *
 * This method prints statistical information derived from the scheduling algorithms' results.
 */
void Scheduler::printStats() const
{
    // Implementation for printing statistics, if needed.
}
