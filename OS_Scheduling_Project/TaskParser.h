#pragma once

#include <vector>
#include "Process.h"
#include <string>

class TaskParser
{
public:
	TaskParser();
	~TaskParser();

	std::vector<Process> parseFile(const std::string& filename);

private:
	
};

