#pragma once
#include <vector>
#include "Process.h"
#include "FCFS_Scheduler.h"
#include "SJF_Scheduler.h"
#include "Priority_Scheduler.h"
#include "RR_Scheduler.h"
#include "PriorityRR_Scheduler.h"

/**
 * @brief Scheduler class for managing different scheduling algorithms.
 *
 * This class coordinates multiple scheduling algorithms including FCFS, SJF,
 * Priority, Round Robin (RR), and Priority Round Robin (PRR). It maintains
 * queues for ready, waiting, and finished processes, and delegates execution
 * to respective scheduler objects.
 */
class Scheduler
{
public:
	/**
	 * @brief Constructor to initialize Scheduler with a vector of processes.
	 *
	 * @param processes Vector of processes to be scheduled.
	 */
	Scheduler(std::vector<Process> processes);

	/**
	 * @brief Destructor for Scheduler class.
	 */
	~Scheduler();

	/**
	 * @brief Executes all scheduling algorithms.
	 *
	 * This method runs each scheduling algorithm sequentially on the set of processes.
	 * Each algorithm calculates and updates process times and manages process queues.
	 */
	void run()														const;

	void printProcesses() const;

protected:
	std::vector<Process> waitingQueue;	// Pointer to the waiting queue

	FCFS_Scheduler fcfs_Scheduler;											// FCFS scheduler object
	SJF_Scheduler sjfScheduler;												// SJF scheduler object
	RR_Scheduler rrScheduler = RR_Scheduler(20);							// RR scheduler object
	Priority_Scheduler priorityScheduler;									// Priority scheduler object
	PriorityRR_Scheduler priorityRRScheduler = PriorityRR_Scheduler(20);	// Priority RR scheduler object
};

