
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double hourlyRate = 85.00;
    int hoursWorked = 40;

    // Calculate gross wages
    double totalWages = hoursWorked * hourlyRate;

    cout << fixed << setprecision(2);
    cout << "--- Wage Calculation ---" << endl;
    cout << "Hours Worked: " << hoursWorked << " hours" << endl;
    cout << "Hourly Rate: R" << hourlyRate << "/hr" << endl;
    cout << "Total Weekly Wages: R" << totalWages << endl;

    // Concept demonstration: Finding average daily wage over 3 main shifts
    // Incorrect (Integer division): totalWages / 3 -> drops decimals if totalWages was int
    // Correct (Floating-point division): dividing by 3.0 preserves decimals
    double averagePerShift = totalWages / 3.0;
    cout << "Average Wage per Shift (3 shifts): R" << averagePerShift << endl;

    return 0;
}
