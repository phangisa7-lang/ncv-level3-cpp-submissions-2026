
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string itemName = "Coding Textbook";
    int quantity = 3;
    double pricePerItem = 81.67;

    // Calculate total using floating-point precision
    double totalCost = quantity * pricePerItem;

    // Format output to 2 decimal places
    cout << fixed << setprecision(2);

    // Display the receipt
    cout << "=============================" << endl;
    cout << "       OFFICIAL RECEIPT      " << endl;
    cout << "=============================" << endl;
    cout << "Item:     " << itemName << endl;
    cout << "Qty:      " << quantity << endl;
    cout << "Price:    R" << pricePerItem << endl;
    cout << "-----------------------------" << endl;
    cout << "TOTAL:    R" << totalCost << endl;
    cout << "=============================" << endl;

    return 0;
}
