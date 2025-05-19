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
	void stamp(Process p) const;

	//Function to print the Gantt chart
	void print() const;

	

private:
	std::vector<GanttChart> stampEntries;
};

