#include <iostream>
#include <cstring>

using namespace std;

class student {
private:
	char* name;
	int* grades;
	int gradeCount;
	int gradeCapacity;

	void resizeGrades() {
		int newCapacity = gradeCapacity * 2;
		int* newGrades = new int[newCapacity];
		memcpy(newGrades, grades, gradeCount * sizeof(int));
		delete[] grades;
		grades = newGrades;
		gradeCapacity = newCapacity;
	}
public:
	//constructor
	student(const char* studentName) {
		name = new char[strlen(studentName) + 1];
		strcpy(name, studentName);
		grades = new int[2];
		gradeCount = 0;
		gradeCapacity = 2;
	}
	~student() {
		delete[] name;
		delete[] grades;
	}

	//add a grade
	void addGrade(int grade) {
		if (gradeCount == gradeCapacity) {
			resizeGrades();
		}
		grades[gradeCount++] = grade;
	}

	// calculate average grade
	double calculateAverage() const {
		if (gradeCount == 0) return 0.0;
		int sum = 0;
		for (int i = 0; i < gradeCount; i++) {
			sum += grades[i];
		}
		return static_cast<double>(sum) / gradeCount;
	}
	void displayInfo() const {
		cout << "Student: " << name << "\n";
		cout << "Grades: ";
		for (int i = 0; i < gradeCount; i++) {
			cout << grades[i] << " ";
		}
		cout << "\nAverage Grade: " << calculateAverage() << "\n";
	}
};

int main() {
	// Create a student object
	student student("John Doe");

	// Add grades
	student.addGrade(85);
	student.addGrade(90);
	student.addGrade(78);
	student.addGrade(92);

	// Display student information
	student.displayInfo();
	return 0;
}