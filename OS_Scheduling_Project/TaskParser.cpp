#include "TaskParser.h"
#include "Process.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

/**
 * @brief Constructor for TaskParser class.
 *
 * Initializes a TaskParser object.
 */
TaskParser::TaskParser()
{
}

/**
 * @brief Destructor for TaskParser class.
 *
 * Cleans up resources used by TaskParser object.
 */
TaskParser::~TaskParser()
{
}

/**
 * @brief Parses a text file to create a vector of Process objects.
 *
 * @param filename The name of the file to be parsed.
 * @return A vector of Process objects parsed from the file.
 * @throws runtime_error if the file cannot be opened.
 */
vector<Process> TaskParser::parseFile(const std::string& filename) const
{
	ifstream inputFile("schedule.txt");

	if (!inputFile.is_open()) throw runtime_error("Could not open file");
	vector<Process> processes;
	string line;
	int pid = 1; // Initialize PID counter

	while (getline(inputFile, line)) {
		assert(pid >= 0 && "PID must be positive"); // Assert that PID is positive

		istringstream iss(line);
		string tName, pri, bt;						// Temporary strings to hold the parsed values
		int priority = 0, burstTime = 0;	

		getline(iss, tName, ' ');	//Read until the first space
		getline(iss, pri, ' ');		// Read until the second space
		getline(iss, bt, ' ');		// Read until the third of the line

		//assert the parsing of the strings
		try
		{
			priority = stoi(pri);
			burstTime = stoi(bt);
			Process process(pid, 0/*arrivalTime = 0 by default*/, burstTime, priority);
			pid = processes.size() + 1 + 1; // Increment PID for each new process
			processes.push_back(process);
			cout << "Parsed Process PID: " << process.getPID() << " CPU Burst: " << process.getBurstTime() << endl;
		}
		catch (const invalid_argument&)
		{
			cerr << "Error parsing line: " << line << endl;
		}

	}
	return processes;
}


