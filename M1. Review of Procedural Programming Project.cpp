// M1. Review of Procedural Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Global constant for number of tests per student
const int NUM_TESTS = 5;
// Max number of students possible
const int MAX_STUDENTS = 100;

// Function prototypes
int readData(ifstream& inFile, string names[], double scores[][NUM_TESTS]);
void calculateAverages(const double scores[][NUM_TESTS], double averages[], int studentCount);
char getLetterGrade(double average);
void printReport(const string names[], const double averages[], int studentCount);

int main() {
    string studentNames[MAX_STUDENTS];
    double testScores[MAX_STUDENTS][NUM_TESTS];
    double averages[MAX_STUDENTS];
    int studentCount;

    ifstream inputFile("StudentGrades.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    studentCount = readData(inputFile, studentNames, testScores);
    inputFile.close();

    calculateAverages(testScores, averages, studentCount);

    printReport(studentNames, averages, studentCount);

    return 0;
}

// Reads student names and scores from file, returns student count
int readData(ifstream& inFile, string names[], double scores[][NUM_TESTS]) {
    int count = 0;
    while (count < MAX_STUDENTS && inFile >> names[count]) {
        for (int j = 0; j < NUM_TESTS; ++j) {
            inFile >> scores[count][j];
        }
        ++count;
    }
    return count;
}

// Calculate averages for each student
void calculateAverages(const double scores[][NUM_TESTS], double averages[], int studentCount) {
    for (int i = 0; i < studentCount; ++i) {
        double sum = 0.0;
        for (int j = 0; j < NUM_TESTS; ++j) {
            sum += scores[i][j];
        }
        averages[i] = sum / NUM_TESTS;
    }
}

// Return letter grade based on average score
char getLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}
//Structure Chart
void printReport(const string names[], const double averages[], int studentCount) {
    cout << left << setw(15) << "Student Name"
        << setw(10) << "Average"
        << "Grade" << endl;
    cout << "--------------------------------" << endl;

    cout << fixed << setprecision(2);
    for (int i = 0; i < studentCount; ++i) {
        cout << left << setw(15) << names[i]
            << setw(10) << averages[i]
            << getLetterGrade(averages[i]) << endl;
    }
}
