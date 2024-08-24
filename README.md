# Student-Enrollment-and-Attendance-Manager

Project Overview
  The Student Management System (SMS) is a software application designed to manage and track the progress of students in various 
  academic courses. It facilitates the enrollment of students into courses, tracks the completion of lectures, manages attendance, 
   and provides detailed reports on students' progress and course requirements.

"Key Features :-" 
Student Enrollment: Add new students to the system with a unique roll number.
Course Enrollment: Enroll students in multiple courses, each with a specified number of total lectures.
Lecture Management: Mark lectures as finished and attended for each course.
Attendance Tracking: Calculate and display the number of additional lectures needed for students to meet a 75% attendance requirement.
Information Reporting: Print detailed reports on students' progress, including lectures finished, attended, and required for meeting attendance goals.


"Classes and Their Responsibilities"
Course
The Course class represents an academic course and provides functionality to track lecture progress and attendance:

Attributes:

totalLectures: Total number of lectures for the course.
lecturesFinished: Number of lectures completed.
lecturesAttended: Number of lectures attended by the student.
Methods:

finishLecture(): Increment the count of finished lectures.
attendLecture(): Increment the count of attended lectures, ensuring it does not exceed finished lectures.
getLecturesLeft() const: Returns the number of lectures remaining to be finished.
getLecturesNeededToAttend() const: Computes the number of additional lectures that need to be attended to reach a 75% attendance rate.
Student
The Student class manages individual students, their courses, and their progress:

Attributes:

rollNumber: Unique identifier for the student.
courses: A map of course names to Course objects, representing the student's enrolled courses.
Methods:

enrollInCourse(const std::string& courseName, int totalLectures): Enrolls the student in a new course.
finishLecture(const std::string& courseName): Marks a lecture as finished for a specific course.
attendLecture(const std::string& courseName): Marks a lecture as attended for a specific course, provided enough lectures have been finished.
printInfo() const: Outputs detailed information about the student's courses and progress.
StudentSystem
The StudentSystem class manages a collection of students and provides functionality to add and retrieve students:

Attributes:

students: A map of roll numbers to Student objects.
Methods:

addStudent(const std::string& rollNumber): Adds a new student to the system.
getStudent(const std::string& rollNumber): Retrieves a pointer to a student by their roll number.
