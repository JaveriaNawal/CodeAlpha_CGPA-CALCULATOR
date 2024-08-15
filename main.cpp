#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
using namespace std;
char bar = 219;

double getGradePoint(char grade)
   {
    switch (grade)
     {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default : return 0.0;
     }
}
class Course
{
public:
    int creditHours;
    char grade;

    Course(int ch, char g) : creditHours(ch), grade(g) {}
};

class Student
{
private:
    vector<Course> courses;

public:
    void addCourse(int creditHours, char grade)
    {
        courses.emplace_back(creditHours, grade);
    }

    double calculateCGPA()
     {
        double totalGradePoints = 0.0;
        int totalCredits = 0;

        for (const auto& course : courses)
    {
            double gradePoint = getGradePoint(course.grade);
            totalGradePoints += gradePoint * course.creditHours;
            totalCredits += course.creditHours;
    }

        return totalCredits > 0 ? totalGradePoints / totalCredits : 0.0;
    }

    void displayGradesAndCredits()
     {
        cout<<endl;
        cout << "\n========================================\n";
        cout << "          Course Grades and Credits\n";
        cout << "========================================\n";
        for (size_t i = 0; i < courses.size(); ++i)
        {
            cout << "Course " << i + 1 << ": Grade = " << courses[i].grade
                 << ", Credits = " << courses[i].creditHours << endl;
        }

        double totalGradePoints = 0.0;
        int totalCredits = 0;

        for (const auto& course : courses)
        {
            totalGradePoints += getGradePoint(course.grade) * course.creditHours;
            totalCredits += course.creditHours;
        }

        cout << "\n----------------------------------------\n";
        cout << "Total Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "CGPA: " << fixed << setprecision(2) << calculateCGPA() << endl;
        cout << "========================================\n";
    }
};

int main() {
    Student student;
    int numCourses;

    cout << "          CGPA Calculator\n";
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i)
    {
        int creditHours;
        char grade;
        cout << "----------------------------------------\n";
        cout << "Course " << i + 1 << ":\n";
        cout << "Enter credit hours: ";
        cin >> creditHours;
        cout << "Enter grade (A, B, C, D, F): ";
        cin >> grade;
        student.addCourse(creditHours, grade);
    }

    student.displayGradesAndCredits();

    return 0;
}
