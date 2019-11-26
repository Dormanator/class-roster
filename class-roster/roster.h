#pragma once
#include <string>
#include "degree.h"
#include "student.h"

const int numStudents = 5;
const string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Ryan,Dorman,rdorma2@wgu.edu,28,4,62,32,SOFTWARE"
};

class Roster {
public:
	static const int maxRosterSize = 5;

	Roster();

	Student* getStudent(int idx);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(string studentID);

	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);

	~Roster();

private:
	int studentsInRoster = 0;
	Student* classRosterArray[maxRosterSize] = {};

	int findStudent(string studentID);
};