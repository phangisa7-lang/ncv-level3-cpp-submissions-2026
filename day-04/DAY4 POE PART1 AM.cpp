#include <iostream>
#include <utility> // Required for std::pair

// Function 1: Prompts the user and returns both numbers
std::pair<double, double> getTwoNumbers() {
    double num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    return std::make_pair(num1, num2);
}

// Function 2: Receives two numbers, calculates, and displays the sum
void calculateAndDisplaySum(double num1, double num2) {
    double sum = num1 + num2;
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << std::endl;
}

// Function 3: Receives two numbers, calculates, and displays the difference
void calculateAndDisplayDifference(double num1, double num2) {
    double difference = num1 - num2;
    std::cout << "The difference (" << num1 << " - " << num2 << ") is: " << difference << std::endl;
}

// Function 4: Receives two numbers, calculates, and displays the product
void calculateAndDisplayProduct(double num1, double num2) {
    double product = num1 * num2;
    std::cout << "The product of " << num1 << " and " << num2 << " is: " << product << std::endl;
}

// Function 5: Receives two numbers, calculates, and displays the quotient
void calculateAndDisplayQuotient(double num1, double num2) {
    // Safety check: Prevent division by zero
    if (num2 == 0) {
        std::cout << "The quotient cannot be calculated: Division by zero is undefined!" << std::endl;
    } else {
        double quotient = num1 / num2;
        std::cout << "The quotient of " << num1 << " / " << num2 << " is: " << quotient << std::endl;
    }
}

int main() {
    // 1. Get the numbers from the user
    auto [first, second] = getTwoNumbers();

    // 2. Run all mathematical operations
    calculateAndDisplaySum(first, second);
    calculateAndDisplayDifference(first, second);
    calculateAndDisplayProduct(first, second);
    calculateAndDisplayQuotient(first, second);

    return 0;
}
