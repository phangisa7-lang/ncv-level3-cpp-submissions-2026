// 1. admission.cpp (Boundary test table included in comments)
/*
Boundary Test Table for Age Input:
--------------------------------------------------------------
Test Case      | Input Value | Expected Outcome / Error Type
--------------------------------------------------------------
Extreme Low    | -5          | Error: Age cannot be negative.
Valid Child    | 5           | Valid: Process child admission.

*/

#include <iostream>
using namespace std;

void processAdmission() {
    int age;
    char choice;

    do {
        cout << "Enter age for admission: ";
        if (!(cin >> age)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (age < 0 || age > 120) {
            cout << "Invalid age! Age must be between 0 and 120.\n";
        } else {
            cout << "Age accepted. Processing admission...\n";
        }

        cout << "Do you want to check another age? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}


// 2. services_switch.cpp and rating_switch.cpp
#include <iostream>
using namespace std;

void runServicesSwitch() {
    int choice;
    do {
        cout << "\n--- South African Classroom Tech Support ---\n";
        cout << "1. Reset Projector Connection\n";
        cout << "2. Check Lab WiFi Status\n";
        cout << "3. Report Missing Lab Equipment\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Fix: Re-plug the HDMI cable and restart the projector.\n";
                break;
            case 2:
                cout << "Status: Eduroam/Lab WiFi is currently stable.\n";
                break;
            case 3:
                cout << "Action: Ticket logged. Inform your lab technician.\n";
                break;
            case 4:
                cout << "Exiting tech support menu.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);
}

void runRatingSwitch() {
    int rating;
    cout << "\nRate today's lesson (1 = Poor, 5 = Excellent): ";
    cin >> rating;

    switch (rating) {
        case 1:
            cout << "Feedback: We will improve. Please specify your issues.\n";
            break;
        case 2:
            cout << "Feedback: Below average. More practice examples needed.\n";
            break;
        case 3:
            cout << "Feedback: Satisfactory. Solid understanding achieved.\n";
            break;
        case 4:
            cout << "Feedback: Good! Very interactive session.\n";
            break;
        case 5:
            cout << "Feedback: Excellent! Everything is clear.\n";
            break;
        default:
            cout << "Error: Rating must be between 1 and 5.\n";
    }
}


// 3. readint.cpp (Handles type and range errors)
#include <iostream>
#include <limits>
using namespace std;

int readInteger(int minVal, int maxVal) {
    int val;
    while (true) {
        cout << "Enter a student ID or grade point (" << minVal << " - " << maxVal << "): ";
        cin >> val;

        // NOTE ON INPUT ERRORS:
        // 1. Type Mismatch Error: Handled by checking if cin failed when parsing text into an integer.
        // 2. Range Bounds Error: Handled by verifying if the integer falls outside the accepted min/max values.
        if (cin.fail()) {
            cout << "Type Error: That is not a valid whole number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (val < minVal || val > maxVal) {
            cout << "Range Error: Value out of bounds. Please try again.\n";
        } else {
            return val;
        }
    }
}


// 4. Trace tables: breakcont and trace
/*
Code Block for 'break':
for (int i = 1; i <= 5; i++) {
    if (i == 3) break;
    cout << i << " ";
}
Trace Table for 'break':
-----------------------------
Iteration | i | i == 3 | Output
-----------------------------
1         | 1 | False  | 1
2         | 2 | False  | 2
3         | 3 | True   | (Loop terminates immediately)
-----------------------------

Code Block for 'continue':
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;
    cout << i << " ";
}
Trace Table for 'continue':
-----------------------------
Iteration | i | i == 3 | Output
-----------------------------
1         | 1 | False  | 1
2         | 2 | False  | 2
3         | 3 | True   | (Skips rest of loop body)
4         | 4 | False  | 4
5         | 5 | False  | 5
-----------------------------
*/


// 5. Corrected week_bug.cpp
#include <iostream>
using namespace std;

void runWeekBugFix() {
    int dayNum;
    cout << "\nEnter day number (1-7): ";
    cin >> dayNum;

    // BUG FIXES APPLIED:
    // 1. Added missing 'break' statements to prevent cascade/fall-through logic errors.
    // 2. Standardized string syntax output patterns.
    switch (dayNum) {
        case 1: cout << "Monday\n"; break;
        case 2: cout << "Tuesday\n"; break;
        case 3: cout << "Wednesday\n"; break;
        case 4: cout << "Thursday\n"; break;
        case 5: cout << "Friday\n"; break;
        case 6: cout << "Saturday\n"; break;
        case 7: cout << "Sunday\n"; break;
        default: cout << "Invalid day number!\n"; break;
    }
}


// Main program wrapper executing all required tasks
int main() {
    cout << "=== TASK 1: Admission Loop ===\n";
    processAdmission();

    cout << "\n=== TASK 2: Switch Services & Ratings ===\n";
    runServicesSwitch();
    runRatingSwitch();

    cout << "\n=== TASK 3: Input Error Handling ===\n";
    int validNum = readInteger(10, 50);
    cout << "Successfully saved valid entry: " << validNum << "\n";

    cout << "\n=== TASK 5: Bug Fixed Week Day Lookup ===\n";
    runWeekBugFix();

    return 0;
}
