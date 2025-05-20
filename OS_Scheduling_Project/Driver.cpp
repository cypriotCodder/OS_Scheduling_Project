/**
 * @file main.cpp
 * @author Nedim Can Huray
 * @date 20-05-2025
 * @brief Main .cpp file of the OS Project.
 */

#include <iostream>
#include "TaskParser.h"
#include "Scheduler.h"

using namespace std;

/**
 * @brief Main function for the OS Scheduling Project.
 *
 * This function initializes the TaskParser and Scheduler to parse task data
 * from a file and execute scheduling algorithms respectively.
 *
 * @return 0 indicating successful execution.
 */
int main()
{
    cout << "This is a simple OS Scheduling Project.\n";
    cout << "This project will implement various scheduling algorithms.\n";
    cout << "The algorithms are implemented in C++.\n\n";

    // Initialize TaskParser to parse task data
    TaskParser taskParser;
    vector<Process> processes = taskParser.parseFile("Tasks.txt");
    cout << "Parsed " << processes.size() << " processes from the file.\n\n";

    // Initialize Scheduler with parsed processes and run scheduling algorithms
    Scheduler scheduler(processes);
    scheduler.run();

    return 0;
}
