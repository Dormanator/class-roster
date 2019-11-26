#include <iostream>
#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent() {
	setDegreeProgram(Degree::SOFTWARE);
}

SoftwareStudent::SoftwareStudent(
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

Degree SoftwareStudent::getDegreeProgram() {
	return Degree::SOFTWARE;
}

void SoftwareStudent::setDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = Degree::SOFTWARE;
	return;
}

void SoftwareStudent::print() {
	this->Student::print();
	cout << "Degree Program: Software" << endl;
	return;
}

SoftwareStudent::~SoftwareStudent() {
	// all clean up currently occurs in base student destructor
}