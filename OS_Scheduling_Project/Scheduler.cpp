#include "Scheduler.h"
#include <iostream>
#include <vector>
#include "Process.h"
#include <cstdlib>

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
 * @brief Executes different scheduling algorithms based on user input.
 *
 * This method displays a menu of available scheduling algorithms (FCFS, SJF, Priority,
 * Round Robin, Priority Round Robin) and executes the selected algorithm on the set
 * of processes stored in the waiting queue. It continuously prompts the user for a menu
 * choice until the user chooses to exit.
 */
void Scheduler::run() const
{
    
	int menuChoice = 0;
    while (menuChoice != 6) {
		std::cout << "\n1. FCFS\n";
        std::cout << "2. SJF\n";
		std::cout << "3. Priority\n";
		std::cout << "4. Round Robin\n";
		std::cout << "5. Priority Round Robin\n";
		std::cout << "6. Exit\n";
		std::cout << "Please select a scheduling algorithm: ";
		std::cin >> menuChoice;

        // Run FCFS Scheduler
        if(menuChoice == 1){
			system("cls");
            std::cout << "\033[37m";
            std::cout << "\n===================== FCFS ALGORITHM =====================\n";
			printProcesses();
            fcfs_Scheduler.run(this->waitingQueue);
        }
        // Run SJF Scheduler
        if (menuChoice == 2) {
            system("cls");
            std::cout << "\033[34m";
            std::cout << "\n===================== SJF ALGORITHM =====================\n";
			printProcesses();
            sjfScheduler.run(this->waitingQueue);
        }
        // Run Priority Scheduler
        if (menuChoice == 3) {
			system("cls");
            std::cout << "\033[36m";
            std::cout << "\n===================== PRIORITY ALGORITHM =====================\n";
			printProcesses();
            priorityScheduler.run(this->waitingQueue);
        }
        // Run Round Robin Scheduler
        if (menuChoice == 4) {
			system("cls");
            std::cout << "\033[33m";
            std::cout << "\n===================== ROUND ROBIN ALGORITHM =====================\n";
			printProcesses();
            rrScheduler.run(this->waitingQueue);
        }
        // Run Priority Round Robin Scheduler
        if (menuChoice == 5) {
			system("cls");
            std::cout << "\033[32m";
            std::cout << "\n===================== PRIORITY ROUND ROBIN ALGORITHM =====================\n";
			printProcesses();
            priorityRRScheduler.run(this->waitingQueue);
        }
		// Exit the program
    }
}

/**
 * @brief Prints information about the processes managed by the Scheduler.
 *
 * This method prints details about the processes currently stored in the waiting queue.
 * It displays each process's PID (Process ID), arrival time, burst time, and priority.
 */
void Scheduler::printProcesses() const
{
	std::cout << "PROCESSES:\n";
	for (const auto& process : waitingQueue) {
		std::cout << "PID: " << process.getPID() << ", Arrival Time: " << process.getArrivalTime()
			<< ", Burst Time: " << process.getBurstTime() << ", Priority: " << process.getPriority() << "\n";
	}
    std::cout << "\n";
}


