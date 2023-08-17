#ifndef EMPLOYEE
#define EMPLOYEE

#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:

	//Constructors
	Employee();

	//setters
	void setEmpNumber(int);
	void setEmpFirstName(string);
	void setEmpLastName(string);
	void setYearsService(int);
	void setFields(int, string, string, int);

	void user();

	//getters
	const int getEmpNumber();
	const string getLastName();
	const string getFirstName();
	const int getYearsService();

	const void print();

	//operators
	bool operator == (const Employee&);
	bool operator != (const Employee&);


private:
	int			EmpNum;
	string		LastName;
	string		FirstName;
	int			YearsService;

};

#endif
