#include "GanttChart.h"
#include "Process.h"
#include <iostream>
#include <vector>

using namespace std;

GanttChart::GanttChart()
{
	// Initialize the Gantt chart with an empty vector of Process objects
	this->stampEntries = vector<Process>();
}

GanttChart::~GanttChart()
{
}

void GanttChart::stamp(Process p)
{
	vector<Process> temp = this->stampEntries; // Create a temporary vector to hold the current entries
	//new entry
	Process newProcess_entry(p.getPID(), p.getArrivalTime(), p.getBurstTime(), p.getPriority());
	newProcess_entry.setStart(p.getStart());
	newProcess_entry.setEnd(p.getEnd());
	temp.push_back(newProcess_entry); // Add the new entry to the temporary vector
	
	// Update the stamp entries with the new vector
	setStampEntries(temp);
}

void GanttChart::print() const
{
	cout << "===================== GANNT CHART =====================\n";
	for (const auto& entry : stampEntries) {
		cout << "[" << entry.getStart() << " ------" << "P" << entry.getPID() << "------ " << entry.getEnd() << "] ";
	}
	cout << endl;
}
