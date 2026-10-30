#include <iostream>
#include <algorithm> // For std::sort (or you can use a manual sort)

// Function prototypes
void populateArray(int arr[], int size);
int countEvenNumbers(const int arr[], int size);
void displayOddNumbers(const int arr[], int size);
void sortArrayAscending(int arr[], int size);
void displayArray(const int arr[], int size);

int main() {
    const int SIZE = 5;
    int myArray[SIZE];

    // 1. Populate the array
    std::cout << "--- Populating Array ---" << std::endl;
    populateArray(myArray, SIZE);

    // 2. Count and return even numbers
    std::cout << "\n--- Checking Even Numbers ---" << std::endl;
    int evenCount = countEvenNumbers(myArray, SIZE);
    std::cout << "Number of even numbers in the array: " << evenCount << std::endl;

    // 3. Display only odd numbers
    std::cout << "\n--- Displaying Odd Numbers ---" << std::endl;
    displayOddNumbers(myArray, SIZE);

    // 4. Sort the array in ascending order
    sortArrayAscending(myArray, SIZE);
    std::cout << "\n[Array has been sorted in ascending order]" << std::endl;

    // 5. Display sorted values
    std::cout << "\n--- Displaying Sorted Array ---" << std::endl;
    displayArray(myArray, SIZE);

    return 0;
}

// 1. Function to populate an array with 5 values from user input
void populateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter value " << (i + 1) << ": ";
        std::cin >> arr[i];
    }
}

// 2. Function to determine and return the number of even numbers in an array
int countEvenNumbers(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// 3. Function to display only odd numbers inside the array
void displayOddNumbers(const int arr[], int size) {
    std::cout << "Odd numbers: ";
    bool foundOdd = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            std::cout << arr[i] << " ";
            foundOdd = true;
        }
    }
    if (!foundOdd) {
        std::cout << "None";
    }
    std::cout << std::endl;
}

// 4. Function to sort all values in the array in ascending order (using Selection Sort)
void sortArrayAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the elements
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 5. Function to display sorted values stored inside the array
void displayArray(const int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
