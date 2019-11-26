#pragma once
#include <string>
#include "degree.h"

using std::string;

class Student {
public:
	static const int numCourses = 3;

	Student();
	Student(string studentID, string firstName, string lastName, int age, string emailAddress, int daysToCompleteCourses[]);

	string getStudentID();
	void setStudentID(string studentID);

	string getFirstName();
	void setFirstName(string firstName);

	string getLastName();
	void setLastName(string lastName);

	string getEmailAddress();
	void setEmailAddress(string emailAddress);

	int getAge();
	void setAge(int age);

	int* getDaysInCourses();
	void setDaysInCourses(int daysInCourses[]);

	Degree virtual getDegreeProgram() = 0;
	void virtual setDegreeProgram(Degree degreeProgram) = 0;
	
	void virtual print();

	~Student();

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourses[numCourses];
	Degree degreeProgram;
};