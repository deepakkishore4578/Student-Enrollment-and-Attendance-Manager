#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Course {
public:
    Course() : totalLectures(0), lecturesFinished(0), lecturesAttended(0) {}
    Course(int totalLectures) 
        : totalLectures(totalLectures), lecturesFinished(0), lecturesAttended(0) {}

    void finishLecture() {
        if (lecturesFinished < totalLectures) {
            lecturesFinished++;
        }
    }

    void attendLecture() {
        if (lecturesAttended < lecturesFinished) {
            lecturesAttended++;
        }
    }

    int getLecturesLeft() const {
        return totalLectures - lecturesFinished;
    }

    int getLecturesNeededToAttend() const {
        int requiredAttended = static_cast<int>(0.75 * totalLectures) - lecturesAttended;
        return (requiredAttended > 0) ? requiredAttended : 0;
    }

    int totalLectures;
    int lecturesFinished;
    int lecturesAttended;
};

class Student {
public:
    Student() {}
    Student(const std::string& rollNumber) : rollNumber(rollNumber) {}

    void enrollInCourse(const std::string& courseName, int totalLectures) {
        courses[courseName] = Course(totalLectures);
    }

    void finishLecture(const std::string& courseName) {
        if (courses.find(courseName) != courses.end()) {
            courses[courseName].finishLecture();
        }
    }

    void attendLecture(const std::string& courseName) {
        if (courses.find(courseName) != courses.end()) {
            courses[courseName].attendLecture();
        }
    }

    void printInfo() const {
        cout << "Student Roll Number: " << rollNumber << endl;
        for (map<std::string, Course>::const_iterator it = courses.begin(); it != courses.end(); ++it) {
            const Course& course = it->second;
            cout << "Course: " << it->first << std::endl;
            cout << "  Total Lectures: " << course.totalLectures << std::endl;
            cout << "  Lectures Finished: " << course.lecturesFinished << std::endl;
            cout << "  Lectures Attended: " << course.lecturesAttended << std::endl;
            cout << "  Lectures Left to Attend for 75% Attendance: " << course.getLecturesNeededToAttend() << std::endl;
        }
    }

private:
    string rollNumber;
    map<std::string, Course> courses;
};

class StudentSystem {
public:
    void addStudent(const std::string& rollNumber) {
        students[rollNumber] = Student(rollNumber);
    }

    Student* getStudent(const std::string& rollNumber) {
        map<std::string, Student>::iterator it = students.find(rollNumber);
        if (it != students.end()) {
            return &it->second;
        }
        return nullptr;
    }

private:
    std::map<std::string, Student> students;
};

int main() {
    StudentSystem system;

    // Add students
    system.addStudent("S001");
    system.addStudent("S002");

    // Enroll students in courses
    Student* student1 = system.getStudent("S001");
    cout<<endl;
    cout<<" ----------- STUDENT 1 information ----------" <<endl;
    cout<<endl;
    
    if (student1) {
        student1->enrollInCourse("CS384", 40);
        student1->enrollInCourse("MA301", 30);
    // Update course progress
    if (student1) {
        student1->finishLecture("MA301");
        student1->attendLecture("MA301");
        student1->finishLecture("CS384");
        student1->finishLecture("CS384");
        student1->finishLecture("CS384");
        student1->finishLecture("CS384");
        student1->attendLecture("CS384");
    }

    // Print student info
    if (student1) {
        student1->printInfo();
    }
     cout<<endl;
    cout<<" ----------- STUDENT 2 information ----------" <<endl;
     cout<<endl;
    // second student 
    Student* student2 = system.getStudent("S002");
    if (student2) {
        student2->enrollInCourse("MA301", 40);
        student2->enrollInCourse("CS384", 30);
    }

    // Update course progress
    if (student2) {
        student2->finishLecture("MA301");
        student2->attendLecture("MA301");
        student2->finishLecture("CS384");
        student2->finishLecture("CS384");
        student2->finishLecture("CS384");
        student2->finishLecture("CS384");
        student2->finishLecture("CS384");
        student2->finishLecture("CS384");
        student2->finishLecture("CS384");
        student2->finishLecture("CS384");
        student2->attendLecture("CS384");
    }

    // Print student info
    if (student2) {
        student2->printInfo();
    }

    return 0;
}}
