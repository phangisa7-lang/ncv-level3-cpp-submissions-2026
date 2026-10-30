#include <iostream>
#include <cstdlib>   // Required for rand() and srand()
#include <ctime>     // Required for time() to seed the random generator

// Prompts the user for two numbers using reference parameters.
void getTwoNumbers(double& num1, double& num2) {
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;
}

// Receives two numbers, calculates their sum, and returns it.
double calculateSum(double a, double b) {
    return a + b;
}

// Receives two numbers, calculates their difference, and returns it.
double calculateDifference(double a, double b) {
    return a - b;
}

// Receives two numbers, calculates their product, and returns it.
double calculateProduct(double a, double b) {
    return a * b;
}

// Receives two numbers, calculates their quotient, and returns it.
double calculateQuotient(double a, double b) {
    if (b == 0) {
        std::cout << "[Warning: Cannot divide by zero! Returning 0.]\n";
        return 0;
    }
    return a / b;
}

int main() {
    // Seed the random number generator using the system clock
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "Starting the random math program...\n\n";

    // 1. Generate 2 random numbers in the range of 1 to 50
    // rand() % 50 yields 0 to 49. Adding 1 shifts the range to 1 to 50.
    double firstNum = (std::rand() % 50) + 1;
    double secondNum = (std::rand() % 50) + 1;

    std::cout << "The two generated numbers are: " << firstNum << " and " << secondNum << "\n";

    // 2. Prompt the user for a mathematical operator
    char mathOperator;
    std::cout << "Enter a valid math operator (+, -, *, /): ";
    std::cin >> mathOperator;

    double result = 0.0;
    bool validOperation = true;

    // 3. Evaluate the choice using a switch statement
    switch (mathOperator) {
        case '+':
            result = calculateSum(firstNum, secondNum);
            break;
        case '-':
            result = calculateDifference(firstNum, secondNum);
            break;
        case '*':
            result = calculateProduct(firstNum, secondNum);
            break;
        case '/':
            result = calculateQuotient(firstNum, secondNum);
            break;
        default:
            // 4. Handle invalid operation input safely
            std::cout << "\nError: '" << mathOperator << "' is not a valid math operator!\n";
            validOperation = false;
            break;
    }

    // 5. Display the result only if the operator was valid
    if (validOperation) {
        std::cout << "\nResult: " << firstNum << " " << mathOperator << " " << secondNum << " = " << result << "\n";
    }

    return 0;
}
