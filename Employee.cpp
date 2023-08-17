#include"Employee.h"

//Constructor
Employee::Employee()
{
	EmpNum = 0;
}

//setters

void Employee::setEmpNumber(int eNum)
{
	EmpNum = eNum;
}

void Employee::setEmpLastName(string LName)
{
	LastName = LName;
}

void Employee::setEmpFirstName(string FName)
{
	FirstName = FName;
}

void Employee::setYearsService(int years)
{
	YearsService = years;
}

void Employee::setFields(int num, string LN, string FN, int years)
{
	EmpNum = num;
	LastName = LN;
	FirstName = FN;
	YearsService = years;
}

void Employee::user()
{
	string inputString;
	int intNumber;

	cout << "Employee Number ";
	cin >> intNumber;
	while (intNumber <= 0)
	{
		cout << "Employee Number ";
		cin >> intNumber;
	}
	EmpNum = intNumber;

	cout << "Last Name: ";
	cin >> inputString;
	LastName = inputString;

	cout << " First Name: ";
	cin >> inputString;
	FirstName = inputString;

	cout << "Years of Service: ";
	cin >> intNumber;
	while (intNumber < 0)
	{
		cout << "Years of Service ";
		cin >> intNumber;

	}
	cout << endl;
	YearsService = intNumber;

}

//getters
const int Employee::getEmpNumber()
{
	return EmpNum;
}

const string Employee::getLastName()
{
	return LastName;
}

const string Employee::getFirstName()
{
	return FirstName;
}

const int Employee::getYearsService()
{
	return YearsService;
}

const void Employee::print()
{

	cout << "Employee Number: ";
	cout << EmpNum << endl;
	cout << "Name: ";
	cout << FirstName << " " << LastName << endl;
	cout << "Years of Service: " << YearsService << endl << endl;
}

//overloads

bool Employee::operator == (const Employee& right)
{
	bool status;
	if (EmpNum == right.EmpNum)
		status = true;
	else
		status = false;
	return status;
}

bool Employee::operator != (const Employee& right)
{
	bool status;

	if (EmpNum != right.EmpNum)
		status = true;
	else
		status = false;
	return status;
}