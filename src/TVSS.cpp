#include <iostream>
#include <string>

using namespace std;

const int NUM_INSTITUTIONS = 3;
const int STUDENTS_PER_INSTITUTION = 2;

// Structure to store student information
struct Student {
    string name;
    string phoneNumber;
    string emailAddress;
    string feedback;
};

// Structure to represent a teacher
struct Teacher {
    string name;
    Student students[STUDENTS_PER_INSTITUTION];
};

// Function to display student information and receive feedback
void giveFeedback(Student& student) {
    cout << "\nStudent Information:\n";
    cout << "Name: " << student.name << endl;
    cout << "Phone Number: " << student.phoneNumber << endl;
    cout << "Email Address: " << student.emailAddress << endl;

    cout << "Feedback: " << student.feedback << endl;

    cout << "\nEnter updated feedback for the student: ";
    getline(cin, student.feedback);
}

// Function to add a new student
void addStudent(Teacher& teacher) {
    Student newStudent;
    cout << "\nEnter information for the new student:\n";
    cout << "Enter student name: ";
    getline(cin, newStudent.name);

    cout << "Enter student phone number: ";
    getline(cin, newStudent.phoneNumber);

    cout << "Enter student email address: ";
    getline(cin, newStudent.emailAddress);

    // Initialize feedback to an empty string
    newStudent.feedback = "";

    // Add the new student to the teacher's students array
    for (int i = 0; i < STUDENTS_PER_INSTITUTION; ++i) {
        if (teacher.students[i].name.empty()) {
            teacher.students[i] = newStudent;
            break;
        }
    }

    cout << "New student added successfully.\n";
}

// Function to delete a student
void deleteStudent(Teacher& teacher) {
    cout << "Enter the index of the student to delete (1-" << STUDENTS_PER_INSTITUTION << "): ";
    int index;
    cin >> index;

    // Validate input
    if (index >= 1 && index <= STUDENTS_PER_INSTITUTION) {
        teacher.students[index - 1] = {};  // Reset the student's data
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Invalid index.\n";
    }

    // Clear the input buffer
    cin.ignore();
}

int main() {
    // Initialize teacher information with sample data
    Teacher teachers[NUM_INSTITUTIONS] = {
        {"Teacher1", {{"Student1", "111-111-1111", "student1@example.com", ""}, {"Student2", "222-222-2222", "student2@example.com", ""}}},
        {"Teacher2", {{"Student3", "333-333-3333", "student3@example.com", ""}, {"Student4", "444-444-4444", "student4@example.com", ""}}},
        {"Teacher3", {{"Student5", "555-555-5555", "student5@example.com", ""}, {"Student6", "666-666-6666", "student6@example.com", ""}}},
    };

    // Prompt for teacher's name or ID
    string teacherName;
    cout << "Enter teacher's name: ";
    getline(cin, teacherName);

    // Find the corresponding teacher
    int teacherIndex = -1;
    for (int i = 0; i < NUM_INSTITUTIONS; ++i) {
        if (teachers[i].name == teacherName) {
            teacherIndex = i;
            break;
        }
    }

    // Display students and get feedback for the specified teacher
    if (teacherIndex != -1) {
        #include <iostream>

        cout << "\n\nTeacher: " << teachers[teacherIndex].name << " (Supervising Institution " << teacherIndex + 1 << ")\n";

        // Display existing students
        cout << "Existing students:\n";
        for (int j = 0; j < STUDENTS_PER_INSTITUTION; ++j) {
            if (!teachers[teacherIndex].students[j].name.empty()) {
                cout << j + 1 << ". " << teachers[teacherIndex].students[j].name << endl;
            }
        }

        // Menu for operations
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Give Feedback\n";
            cout << "2. Add Student\n";
            cout << "3. Delete Student\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            // Clear the input buffer
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter the index of the student to give feedback (1-" << STUDENTS_PER_INSTITUTION << "): ";
                    int feedbackIndex;
                    cin >> feedbackIndex;

                    // Validate input
                    if (feedbackIndex >= 1 && feedbackIndex <= STUDENTS_PER_INSTITUTION &&
                        !teachers[teacherIndex].students[feedbackIndex - 1].name.empty()) {
                        giveFeedback(teachers[teacherIndex].students[feedbackIndex - 1]);
                    } else {
                        cout << "Invalid index or empty student.\n";
                    }

                    // Clear the input buffer
                    cin.ignore();
                    break;
                case 2:
                    addStudent(teachers[teacherIndex]);
                    break;
                case 3:
                    deleteStudent(teachers[teacherIndex]);
                    break;
                case 0:
                    cout << "Exiting program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choice != 0);
    } else {
        cout << "Teacher not found.\n";
    }

    return 0;
}
