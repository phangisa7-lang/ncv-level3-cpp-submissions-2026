
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Constants
    const double FARE = 18.00;
    const int MAX_PASSENGERS = 15;

    // Counters and trackers
    int totalTrips = 0;
    int totalPassengers = 0;
    int busiestTrip = 0;
    int inputPassengers = -1;

    cout << "--- Taxi Day Log (Mabopane to Pretoria) ---" << endl;
    cout << "Enter passengers per trip (1-15). Enter 0 to end the day:\n" << endl;

    // Repetition structure (Loop ends when 0 is entered)
    while (true) {
        cout << "Enter passengers: ";
        cin >> inputPassengers;

        // Selection structure for ending the day
        if (inputPassengers == 0) {
            break;
        }

        // Input Validation (Rejects numbers < 0 or > 15)
        if (inputPassengers < 0 || inputPassengers > MAX_PASSENGERS) {
            cout << "Invalid input! Passengers must be between 0 and 15." << endl;
            continue; // Skip processing and ask for input again
        }

        // Process valid trip data
        totalTrips++;
        totalPassengers += inputPassengers;

        // Selection structure to determine the busiest trip
        if (inputPassengers > busiestTrip) {
            busiestTrip = inputPassengers;
        }
    }

    // Financial Calculation
    double totalIncome = totalPassengers * FARE;

    // Display formatted output matching the slide example
    cout << fixed << setprecision(2);
    cout << "\n===============================" << endl;
    cout << "Trips:          " << totalTrips << endl;
    cout << "Passengers:     " << totalPassengers << endl;
    cout << "Income:         R" << totalIncome << endl;
    cout << "Busiest trip:   " << busiestTrip << " passengers" << endl;
    cout << "===============================" << endl;

    return 0;
}
