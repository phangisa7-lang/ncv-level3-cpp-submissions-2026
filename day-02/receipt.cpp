
#include <iostream>
#include <string>

using namespace std;

int main() {
    int studentID;
    string studentName;

    cout << "Enter Student ID: ";
    cin >> studentID;

    // FIX: Clear the newline character left in the buffer by 'cin >>'
    // Without this, the upcoming getline() would read the empty newline and skip ahead.
    cin.ignore();

    cout << "Enter Full Name: ";
    getline(cin, studentName); // Now it successfully reads spaces and strings properly

    // Display confirmation
    cout << "\n--- Student Registered ---" << endl;
    cout << "ID:   " << studentID << endl;
    cout << "Name: " << studentName << endl;

    return 0;
}
