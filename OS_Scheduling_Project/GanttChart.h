#pragma once

class GanttChart
{
public:
	GanttChart();
	~GanttChart();

	//Function to stamp the PID from t-start to t-end
	void stamp(int t_start, int t_end, int pid);

	//Function to print the Gantt chart
	void print() const;

private:

};

