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
 * @brief Executes scheduling algorithms.
 *
 * This method sequentially runs several scheduling algorithms on the waiting queue:
 * FCFS, SJF, Priority, Round Robin, and Priority Round Robin.
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
            std::cout << "\n===================== FCFS ALGORITHM =====================\n";
            fcfs_Scheduler.run(this->waitingQueue);
        }
        // Run SJF Scheduler
        if (menuChoice == 2) {
            system("cls");
            std::cout << "\n===================== SJF ALGORITHM =====================\n";
            sjfScheduler.run(this->waitingQueue);
        }
        // Run Priority Scheduler
        if (menuChoice == 3) {
			system("cls");
            std::cout << "\n===================== PRIORITY ALGORITHM =====================\n";
            priorityScheduler.run(this->waitingQueue);
        }
        // Run Round Robin Scheduler
        if (menuChoice == 4) {
			system("cls");
            std::cout << "\n===================== ROUND ROBIN ALGORITHM =====================\n";
            rrScheduler.run(this->waitingQueue);
        }
        // Run Priority Round Robin Scheduler
        if (menuChoice == 5) {
			system("cls");
            std::cout << "\n===================== PRIORITY ROUND ROBIN ALGORITHM =====================\n";
            priorityRRScheduler.run(this->waitingQueue);
        }
		// Exit the program
    }
}


