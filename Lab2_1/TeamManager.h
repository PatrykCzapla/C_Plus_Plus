#pragma once

#include "Employee.h"
#include <unordered_map>
#include <functional>
#include <algorithm>

class TeamManager
{
	unordered_map<string, vector<Employee>> teams;
public:
	//uzupełnić o funkcję addTeam
	//uzupełnić o funkcję performLambdaOnTasksTeam

	vector<Employee> getTeam(const string& taskName)
	{
		if (teams.find(taskName) != teams.end())
			return teams[taskName];
		return vector<Employee>(0);
	}
};