#include <iostream>
#include "networkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent() {
	setDegreeProgram(Degree::NETWORK);
}

NetworkStudent::NetworkStudent(
	string studentID, 
	string firstName, 
	string lastName, 
	int age, 
	string emailAddress, 
	int daysToCompleteCourses[], 
	Degree degreeProgram
) : Student(
	studentID,
	firstName,
	lastName,
	age,
	emailAddress,
	daysToCompleteCourses
) {
	setDegreeProgram(degreeProgram);
}

Degree NetworkStudent::getDegreeProgram() {
	return Degree::NETWORK;
}

void NetworkStudent::setDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = Degree::NETWORK;
	return;
}

void NetworkStudent::print() {
	this->Student::print();
	cout << "Degree Program: Network" << endl;
	return;
}

NetworkStudent::~NetworkStudent() {
	// all clean up currently occurs in base student destructor
}