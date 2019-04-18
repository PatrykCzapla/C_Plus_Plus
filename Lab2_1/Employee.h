#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class Employee {
public:
	Employee() {}
	Employee(const string &Name, const unsigned int &Age, const double& Salary) :
		Name(Name), Age(Age), Salary(Salary)
	{}

	//uzupełnić o brakujące operatory
	friend bool operator>(const Employee& a, const Employee& b)
	{
		string s1 = a.GetName();
		string s2 = b.GetName();
		transform(s1.begin(), s1.end(), s1.begin(), tolower);
		transform(s2.begin(), s2.end(), s2.begin(), tolower);
		return (s1 < s2);
	}

	friend ostream &operator<<(std::ostream &out, const Employee &in)
	{
		out << setw(10) << in.Name << " " << in.Age << " -- " << in.Salary;
		return out;
	}

	string GetName() const { return Name; }
	double GetSalary() const { return Salary; }
	unsigned int GetAge() const { return Age; }
	void SetSalary(const double newSalary) { Salary = newSalary; }

private:
	string Name;
	double Salary;
	unsigned int Age;
};