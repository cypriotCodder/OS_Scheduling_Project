#pragma once
#include <vector>
#include <iostream>
#include "Process.h"

class GanttChart
{
public:
	GanttChart();
	~GanttChart();

	//Function to stamp the PID from t-start to t-end
	void stamp(Process p);

	//Function to print the Gantt chart
	void print()			const;

	//Setter
	void setStampEntries(std::vector<Process> stampEntries) { this->stampEntries = stampEntries; }
	//Getter for the stamp entries
	const std::vector<Process> getStampEntries() const { return stampEntries; }

private:
	std::vector<Process> stampEntries;
};

