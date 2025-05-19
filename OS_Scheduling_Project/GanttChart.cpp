#include "GanttChart.h"
#include "Process.h"
#include <iostream>

using namespace std;

GanttChart::GanttChart()
{
}

GanttChart::~GanttChart()
{
}

void GanttChart::stamp(int t_start, int t_end, int pid)
{
	//new entry
	Process newProcess_entry;
	newProcess_entry.t_start = t_start;
	newProcess_entry.t_end = t_end;

}

void GanttChart::print() const
{
	
}
