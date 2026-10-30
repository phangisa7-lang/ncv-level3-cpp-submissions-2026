
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
