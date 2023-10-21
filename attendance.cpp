#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Define a struct to represent a student
struct Student {
    int id;
    std::string name;
    bool present;
};

// Function to add a new student to the system
void addStudent(std::vector<Student>& students) {
    Student student;
    student.id = students.size() + 1;
    
    std::cout << "Enter student's name: ";
    std::cin >> student.name;
    
    student.present = false;
    
    students.push_back(student);
    std::cout << "Student added successfully." << std::endl;
}

// Function to mark attendance for a student
void markAttendance(std::vector<Student>& students) {
    int studentId;
    std::cout << "Enter student ID: ";
    std::cin >> studentId;
    
    if (studentId >= 1 && studentId <= students.size()) {
        students[studentId - 1].present = true;
        std::cout << "Attendance marked for student: " << students[studentId - 1].name << std::endl;
    } else {
        std::cout << "Invalid student ID." << std::endl;
    }
}

// Function to display the attendance report
void displayAttendanceReport(const std::vector<Student>& students) {
    std::cout << "Attendance Report" << std::endl;
    std::cout << "ID\tName\tAttendance" << std::endl;
    
    for (const Student& student : students) {
        std::cout << student.id << "\t" << student.name << "\t" << (student.present ? "Present" : "Absent") << std::endl;
    }
}

int main() {
    std::vector<Student> students;
    
    while (true) {
        std::cout << "Attendance Management System" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Mark Attendance" << std::endl;
        std::cout << "3. Display Attendance Report" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                markAttendance(students);
                break;
            case 3:
                displayAttendanceReport(students);
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    
    return 0;
}
