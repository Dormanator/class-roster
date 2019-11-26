#include <iostream>
#include "student.h"

using namespace std;

// default constructor for sode default values
Student::Student() { 
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	memset(daysInCourses, 0, sizeof(int) * numCourses); // initalize array elements to 0
}

Student::Student(string studentID, string firstName, string lastName, int age, string emailAddress, int daysInCourses[]) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;

	// deep copy arr argument into object to avoid manipulating the array passed in
	for (int i = 0; i < numCourses; i++) {
		this->daysInCourses[i] = daysInCourses[i];
	} 
}

string Student::getStudentID() {
	return studentID;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
	return;
}

string Student::getFirstName() {
	return this->firstName;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

string Student::getLastName() {
	return lastName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}

string Student::getEmailAddress() {
	return emailAddress;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

int Student::getAge() {
	return age;
}

void Student::setAge(int age) {
	this->age = age;
	return;
}


int* Student::getDaysInCourses() {
	return daysInCourses;
}

void Student::setDaysInCourses(int daysInCourses[]) {
	for (int i = 0; i < numCourses; i++) { // FIX ME - ensure parmeters size is correct to not ref values out of bounds
		this->daysInCourses[i] = daysInCourses[i];
	}
	return;
}

void Student::print() {
	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Age: " << age << "\t";
	cout << "daysInCourse: " << "{ " << daysInCourses[0] << ", " << daysInCourses[1] << ", " << daysInCourses[2] << " } ";
	return;
}

Student::~Student() {
	// array is on stack and will be destoryed when student class is
}
