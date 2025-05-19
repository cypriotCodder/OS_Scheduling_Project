#include "GanttChart.h"
#include "Process.h"
#include <iostream>
#include <vector>

using namespace std;

GanttChart::GanttChart()
{
}

GanttChart::~GanttChart()
{
}

void GanttChart::stamp(Process p)
{
	//new entry
	Process newProcess_entry(p.getPID(), p.getArrivalTime(), p.getBurstTime(), p.getRemainingTime(), p.getPriority());
	newProcess_entry.setStart(p.getStart());
	newProcess_entry.setEnd(p.getEnd());
	//stampEntries.push_back(newProcess_entry); //TODO
}

void GanttChart::print() const
{
	
}
