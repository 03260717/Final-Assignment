#include <iostream>
#include <string>
using namespace std;

string programName1 = "";
string programName2 = "";
int maxSeats1 = 0, maxSeats2 = 0;
int minPercentage1 = 0, minPercentage2 = 0;
int availableSeats1 = 0, availableSeats2 = 0;

string studentName = "";
int obtainedMarks = 0, totalMarks = 0;
string appliedProgram = "";
string admissionStatus = "";
string rejectionReason = "";

void adminLogin() {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        cout << "Admin login successful!\n";
    } else {
        cout << "Invalid credentials. Returning to main menu.\n";
        return;
    }

    int choice;
    cout << "\nAdmin Menu:\n";
    cout << "1. Add Program\n";
    cout << "2. View Application Status\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        if (programName1 == "") {
            cout << "Enter program name: ";
            cin >> programName1;
            cout << "Enter maximum seats (2-5): ";
            cin >> maxSeats1;
            availableSeats1 = maxSeats1;
            cout << "Enter minimum eligibility percentage: ";
            cin >> minPercentage1;
            cout << "Program " << programName1 << " added successfully!\n";
        } else if (programName2 == "") {
            cout << "Enter program name: ";
            cin >> programName2;
            cout << "Enter maximum seats (2-5): ";
            cin >> maxSeats2;
            availableSeats2 = maxSeats2;
            cout << "Enter minimum eligibility percentage: ";
            cin >> minPercentage2;
            cout << "Program " << programName2 << " added successfully!\n";
        } else {
            cout << "Maximum program limit reached.\n";
        }
    } else if (choice == 2) {
        if (studentName == "") {
            cout << "No applications received yet.\n";
        } else {
            cout << "\nStudent Name: " << studentName << "\n";
            cout << "Applied Program: " << appliedProgram << "\n";
            cout << "Admission Status: " << admissionStatus << "\n";
            if (admissionStatus == "Rejected") {
                cout << "Rejection Reason: " << rejectionReason << "\n";
            }
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void studentApplication() {
    cout << "Enter your name: ";
    cin >> studentName;
    cout << "Enter your obtained marks: ";
    cin >> obtainedMarks;
    cout << "Enter total marks: ";
    cin >> totalMarks;

    float percentage = (float(obtainedMarks) / totalMarks) * 100;

    cout << "Available Programs:\n";
    if (programName1 != "") {
        cout << "1. " << programName1 << "\n";
    }
    if (programName2 != "") {
        cout << "2. " << programName2 << "\n";
    }

    int choice;
    cout << "Choose a program (1 or 2): ";
    cin >> choice;

    if (choice == 1 && programName1 != "") {
        appliedProgram = programName1;
        if (percentage < minPercentage1) {
            admissionStatus = "Rejected";
            rejectionReason = "Does not meet eligibility criteria.";
        } else if (availableSeats1 <= 0) {
            admissionStatus = "Rejected";
            rejectionReason = "No available seats.";
        } else {
            admissionStatus = "Accepted";
            availableSeats1--;
        }
    } else if (choice == 2 && programName2 != "") {
        appliedProgram = programName2;
        if (percentage < minPercentage2) {
            admissionStatus = "Rejected";
            rejectionReason = "Does not meet eligibility criteria.";
        } else if (availableSeats2 <= 0) {
            admissionStatus = "Rejected";
            rejectionReason = "No available seats.";
        } else {
            admissionStatus = "Accepted";
            availableSeats2--;
        }
    } else {
        cout << "Invalid program choice.\n";
        return;
    }

    if (admissionStatus == "Accepted") {
        cout << "Congratulations! You are admitted to " << appliedProgram << ".\n";
    } else {
        cout << "Application Rejected. Reason: " << rejectionReason << ".\n";
    }
}

void viewPrograms() {
    cout << "\nAvailable Programs:\n";
    if (programName1 != "") {
        cout << "1. " << programName1 << " (Seats: " << availableSeats1 << ")\n";
    }
    if (programName2 != "") {
        cout << "2. " << programName2 << " (Seats: " << availableSeats2 << ")\n";
    }
}

int main() {
    int mainChoice;
    cout << "\nMain Menu:\n";
    cout << "1. Login as Admin\n";
    cout << "2. Apply as Student\n";
    cout << "3. View Available Programs\n";
    cout << "Enter your choice: ";
    cin >> mainChoice;

    if (mainChoice == 1) {
        adminLogin();
    } else if (mainChoice == 2) {
        studentApplication();
    } else if (mainChoice == 3) {
        viewPrograms();
    } else {
        cout << "Invalid choice. Exiting program.\n";
    }

    return 0;
}
