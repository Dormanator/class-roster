#pragma once
#include <string>
#include "degree.h"
#include "student.h"

using std::string;

class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, int age, string emailAddress, int daysToCompleteCourses[], Degree degreeProgram);

	// override from Student
	Degree getDegreeProgram() override;
	void setDegreeProgram(Degree degreeProgram) override;

	void print() override;

	~SoftwareStudent();
};
