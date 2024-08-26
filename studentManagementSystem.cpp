#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    float grade;

public:
    // Constructor to initialize a student
    Student(int id, const string& name, int age, float grade) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    float getGrade() const { return grade; }

    // Setters
    void setName(const string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGrade(float grade) { this->grade = grade; }

    // Display student information
    void display() const {
        cout << id << "\t" << name << "\t" << age << "\t" << grade << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    // Add a new student
    void addStudent() {
        int id, age;
        float grade;
        string name;
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Age: ";
        cin >> age;
        cout << "Enter Student Grade: ";
        cin >> grade;

        students.emplace_back(id, name, age, grade);
        cout << "Student added successfully!\n";
    }

    // View all students
    void viewStudents() const {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }
        cout << "ID\tName\tAge\tGrade\n";
        for (const auto& student : students) {
            student.display();
        }
    }

    // Search for a student by ID
    void searchStudent() const {
        int id;
        cout << "Enter Student ID to search: ";
        cin >> id;

        for (const auto& student : students) {
            if (student.getId() == id) {
                cout << "Student found:\n";
                student.display();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Update an existing student's details
    void updateStudent() {
        int id;
        cout << "Enter Student ID to update: ";
        cin >> id;

        for (auto& student : students) {
            if (student.getId() == id) {
                string name;
                int age;
                float grade;

                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new age: ";
                cin >> age;
                cout << "Enter new grade: ";
                cin >> grade;

                student.setName(name);
                student.setAge(age);
                student.setGrade(grade);

                cout << "Student details updated successfully!\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Delete a student record
    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                cout << "Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sms.addStudent(); break;
            case 2: sms.viewStudents(); break;
            case 3: sms.searchStudent(); break;
            case 4: sms.updateStudent(); break;
            case 5: sms.deleteStudent(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice, please try again.\n";
        }
    }
}
