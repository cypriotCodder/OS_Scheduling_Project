#include "GanttChart.h"
#include "Process.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Constructor to initialize an empty Gantt chart.
 *
 * Initializes the Gantt chart with an empty vector of Process entries.
 */
GanttChart::GanttChart()
{
	// Initialize the Gantt chart with an empty vector of Process objects
	this->stampEntries = vector<Process>();
}

/**
 * @brief Destructor for the GanttChart class.
 *
 * Ensures proper cleanup of resources.
 */
GanttChart::~GanttChart()
{
}

/**
 * @brief Adds a new entry to the Gantt chart.
 *
 * @param p Process object representing the entry to be added.
 *
 * Creates a new Process entry with relevant details (PID, start time, end time) and adds it to the Gantt chart.
 */
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

/**
 * @brief Prints the Gantt chart.
 *
 * Prints the Gantt chart entries in the format: [start_time ------PID------ end_time].
 */
void GanttChart::print() const
{
	cout << "===================== GANNT CHART =====================\n";
	for (const auto& entry : stampEntries) {
		cout << "[" << entry.getStart() << " ------" << "P" << entry.getPID() << "------ " << entry.getEnd() << "] ";
	}
	cout << endl;
}
