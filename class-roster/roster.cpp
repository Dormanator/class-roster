#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

using namespace std;

Roster::Roster() {
	// initalize array of ptrs to safe values by default
	for (int i = 0; i < maxRosterSize; i++) {
		classRosterArray[i] = nullptr;
	}
}

Student* Roster::getStudent(int idx) {
	return classRosterArray[idx];
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {

	if (studentsInRoster < maxRosterSize) {
		for (int i = 0; i < maxRosterSize; i++) {
			if (classRosterArray[i] == nullptr) {
				int daysInCourses[Student::numCourses] = { daysInCourse1, daysInCourse2, daysInCourse3 };

				switch (degreeProgram) {
				case Degree::SOFTWARE:
					classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, age, emailAddress, daysInCourses, degreeProgram);
					break;
				case Degree::SECURITY:
					classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, age, emailAddress, daysInCourses, degreeProgram);
					break;
				case Degree::NETWORK:
					classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, age, emailAddress, daysInCourses, degreeProgram);
					break;
				}

				studentsInRoster++;
				return;
			}
		}
	}
	else {
		cout << "The roster currently holds the maximum number of students (" << maxRosterSize << "). Please remove a student first.\n";
		return;
	}
	
}

void Roster::remove(string studentID) {
	int indexInRoster = findStudent(studentID);

	if(indexInRoster >= 0) {
		delete classRosterArray[indexInRoster];
		classRosterArray[indexInRoster] = nullptr;
		studentsInRoster--;
	}
	else {
		cout << "A student with this ID was not found.\n";
	}
	return;
}

void Roster::printAll() {
	for (int i = 0; i < maxRosterSize; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	return;
}

void Roster::printAverageDaysInCourse(string studentID) {
	int indexInRoster = findStudent(studentID);

	int* daysInCourses = classRosterArray[indexInRoster]->getDaysInCourses();
	int sumOfDays = 0;

	for (int i = 0; i < Student::numCourses; i++) {
		sumOfDays += daysInCourses[i];
	}

	cout << sumOfDays / Student::numCourses  << endl;
	return;
}

void Roster::printInvalidEmails() {
	regex validEmailPattern("\\S*\\w+[@]\\S*\\w+[.]\\S*\\w+");
	string invalidEmails = "";


	for (int i = 0; i < maxRosterSize; i++) {
		if (classRosterArray[i] != nullptr && !regex_match(classRosterArray[i]->getEmailAddress(), validEmailPattern)) {
			invalidEmails += classRosterArray[i]->getEmailAddress() + "\n";
		}
	}

	if (!invalidEmails.empty()) {
		cout << invalidEmails;
	}
	else {
		cout << "No invalid emails found.\n";
	}
	return;
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i < maxRosterSize; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	return;
}

int Roster::findStudent(string studentID) {
	for (int i = 0; i < maxRosterSize; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			return i;
		}
	}
	return -1;
}

Roster::~Roster() {
	// clean up ptrs from roster
	for (int i = 0; i < maxRosterSize; i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
}

// helper functions for parsing student data
vector<string> split(const string& delimitedStr, char delimiter) {
	vector<string> strVector;
	string strChunk;
	stringstream strStream(delimitedStr);

	while (getline(strStream, strChunk, delimiter)) {
		strVector.push_back(strChunk);
	}

	return strVector;
}

Degree convertDegreeProgram(string degreeProgramStr) {
	Degree degreeProgram = Degree::SOFTWARE;

	if (degreeProgramStr == "SECURITY") {
		degreeProgram = Degree::SECURITY;
	}
	else if (degreeProgramStr == "NETWORK") {
		degreeProgram = Degree::NETWORK;
	}

	return degreeProgram;
}

int main() {
	// my info
	cout << "SCRIPTING AND PROGRAMMING APPLICATIONS - C867" << endl;
	cout << "C++" << endl;
	cout << "#001002824" << endl;
	cout << "Ryan Dorman" << endl << endl;

	// initalize roster on stack
	Roster classRoster;

	// populate roster
	for (int i = 0; i < numStudents; i++) {
		vector<string> splitStr = split(studentData[i], ',');
		classRoster.add(
			splitStr[0], 
			splitStr[1], 
			splitStr[2], 
			splitStr[3], 
			stoi(splitStr[4]), 
			stoi(splitStr[5]), 
			stoi(splitStr[6]), 
			stoi(splitStr[7]), 
			convertDegreeProgram(splitStr[8])
		);
	}

	// tests
	classRoster.printAll();
		
	classRoster.printInvalidEmails();
		
	for (int i = 0; i < Roster::maxRosterSize; i++) {
		if (classRoster.getStudent(i) != nullptr) {
			classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
		}
	}

	classRoster.printByDegreeProgram(Degree::SOFTWARE);

	classRoster.remove("A3");

	classRoster.remove("A3");

	return 0;
}