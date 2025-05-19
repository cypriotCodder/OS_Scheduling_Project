#include "TaskParser.h"
#include "Process.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

TaskParser::TaskParser()
{
}

TaskParser::~TaskParser()
{
}

vector<Process> TaskParser::parseFile(const std::string& filename)
{
	ifstream inputFile("Tasks.txt");

	if (!inputFile.is_open()) throw runtime_error("Could not open file");
	vector<Process> processes;
	string line;

	while (getline(cin, line)) {
		istringstream iss(line);
		int pid, arrivalTime, burstTime, remainingTime, priority;
		if (!(iss >> pid >> arrivalTime >> burstTime >> remainingTime >> priority)) {
			cerr << "Error parsing line: " << line << endl;
			continue; // Skip this line if parsing fails
		}
		Process process(pid, arrivalTime, burstTime, remainingTime, priority);
		processes.push_back(process);
		cout << "Parsed Process: " << process.getPID() << endl;

	}
	return processes;
}


