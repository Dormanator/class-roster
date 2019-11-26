#include <iostream>
#include "securityStudent.h"

using namespace std;

SecurityStudent::SecurityStudent() {
	setDegreeProgram(Degree::SECURITY);
}

SecurityStudent::SecurityStudent(
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

Degree SecurityStudent::getDegreeProgram() {
	return Degree::SECURITY;
}

void SecurityStudent::setDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = Degree::SECURITY;
	return;
}

void SecurityStudent::print() {
	this->Student::print();
	cout << "Degree Program: Security" << endl;
	return;
}

SecurityStudent::~SecurityStudent() {
	// all clean up currently occurs in base student destructor
}