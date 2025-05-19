/** */
#include <iostream>
#include "TaskParser.h"
#include "Scheduler.h"

using namespace std;

int main()
{
	cout << "This is a simple OS Scheduling Project.\n";
	cout << "This project will implement various scheduling algorithms.\n";
	cout << "The algorithms are implemented in C++.\n\n";

	//to test the TaskParser
	TaskParser taskParser;
	vector<Process> processes = taskParser.parseFile("Tasks.txt");
	cout << "Parsed " << processes.size() << " processes from the file.\n";

	//to test the Scheduler
	Scheduler scheduler(processes);
	scheduler.run();

	return 0;
}

