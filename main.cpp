#include <iostream>
using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_COURSES = 5;

struct Course {
    string name;
    float grade;
    float weight;
};

struct Student {
    string name;
    Course courses[MAX_COURSES];
    int courseCount;
};

// محاسبه معدل
float calculateAverage(Student s) {
    float sum = 0;
    float totalWeight = 0;

    for (int i = 0; i < s.courseCount; i++) {
        sum += s.courses[i].grade * s.courses[i].weight;
        totalWeight += s.courses[i].weight;
    }

    if (totalWeight == 0)
        return 0;

    return sum / totalWeight;
}

// تعیین وضعیت تحصیلی
string getStatus(float avg) {
    if (avg >= 12)
        return "Accepted";
    else if (avg >= 10)
        return "Conditional";
    else
        return "Failed";
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount;

    cout << "Enter number of students: ";
    cin >> studentCount;

    for (int i = 0; i < studentCount; i++) {
        cout << "Enter student name: ";
        cin >> students[i].name;

        cout << "Enter number of courses: ";
        cin >> students[i].courseCount;

        for (int j = 0; j < students[i].courseCount; j++) {
            cout << "Course name: ";
            cin >> students[i].courses[j].name;

            cout << "Grade: ";
            cin >> students[i].courses[j].grade;

            cout << "Weight: ";
            cin >> students[i].courses[j].weight;
        }
    }

    cout << "\n--- Students Report ---\n";

    for (int i = 0; i < studentCount; i++) {
        float avg = calculateAverage(students[i]);
        cout << "Name: " << students[i].name << endl;
        cout << "Average: " << avg << endl;
        cout << "Status: " << getStatus(avg) << endl;
        cout << "----------------------\n";
    }

    return 0;
}
