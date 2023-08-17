// Assignment6.cpp : Cesar Roncancio
//

#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "Employee.h"
using namespace std;

void readFile(BinaryTree&);
void addToTree(BinaryTree&);
void deleteFromTree(BinaryTree&);

int main()
{
	BinaryTree employeeTree;
    readFile(employeeTree);
    cout << "Printing the Employee Tree:" << endl;
    employeeTree.displayInOrder();
    cout << "Current number of employees on the list:" << endl;
    employeeTree.COUNT();
    cout << "Adding a new employee:" << endl;
    addToTree(employeeTree);
    cout << "Printing the Employee Tree:" << endl;
    employeeTree.displayInOrder();
    cout << "Current number of employees on the list:" << endl;
    employeeTree.COUNT();
    cout << "Removing an employee:" << endl;
    deleteFromTree(employeeTree);
    cout << "Printing the Employee Tree:" << endl;
    employeeTree.displayInOrder();
    cout << "Current number of employees on the list:" << endl;
    employeeTree.COUNT();
}
//this method uses ifstream to read from the Employees txt file and then uses the setters on the Employee class to create the object newEmp and finaly adds it to the Binary Tree with the ADD method
//and does this for every line on the original Employees txt
void readFile(BinaryTree& employeeTree) {
    int empNum, years;
    string firstName, lastName;
    Employee newEmp;
    ifstream input;

    input.open("Employees.txt");

    while (input) {
        input >> empNum >> firstName >> lastName >> years;
        if (input) {
            newEmp.setEmpNumber(empNum);
            newEmp.setEmpFirstName(firstName);
            newEmp.setEmpLastName(lastName);
            newEmp.setYearsService(years);
            employeeTree.ADD(newEmp.getEmpNumber());
        }
    }
    input.close();
}
//this method creates a Employee object newEmp uses the user() method to assign the empNo, firstName, LastName, YearsOfService and the uses ADD to add the newEmp to the Tree
void addToTree(BinaryTree& employeeTree) {
    Employee newEmp;
    newEmp.user();
    employeeTree.ADD(newEmp.getEmpNumber());
}
//this method uses the setEmpNumber() setter method to assign the removedEmp object the empNum the user entered and then uses DELETE to remove it.

void deleteFromTree(BinaryTree& employeeTree) {
    Employee removedEmp;
    int empNum;
    cout << "Enter the Employee Number of the employee to remove: " << endl;
    cin >> empNum;
    removedEmp.setEmpNumber(empNum);
    employeeTree.REMOVE(empNum);
    
}