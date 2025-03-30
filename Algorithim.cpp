#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// Selection Sort
void selectionSort(int array[], int length) {
    for (size_t i = 0; i < length; i++) {
        int smallestIndex = i;
        for (size_t j = i + 1; j < length; j++) {
            if (array[smallestIndex] > array[j]) {
                smallestIndex = j;
            }
        }
        swap(array[smallestIndex], array[i]);
    }

    cout << "\nSelection sort result:\n";
    for (size_t i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Insertion Sort
void insertionSort(int array[], int length) {
    for (int i = 1; i < length; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }

    cout << "\nInsertion sort result:\n";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int array[], int length) {
    for (size_t i = 0; i < length - 1; i++) {
        bool swaped = false; // Reset flag in each outer loop
        for (size_t j = 0; j < length - 1 - i; j++) { // Optimize loop
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swaped = true;
            }
        }
        if (!swaped) break; // If no swaps, the array is sorted
    }

    cout << "\nBubble sort result:\n";
    for (size_t i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Linear Search
int linearSearch(int array[], int target, int length) {
    for (size_t i = 0; i < length; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search (Assumes the array is already sorted)
int binarySearch(int array[], int target, int length) {
    sort(array, array + length); // Ensure array is sorted
    int low = 0, high = length - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int option = 0;
    int arraySize = 0;
    int *nums = nullptr;
    int target;

    do {
        cout << "Select Type of Algorithm" << endl;
        cout << "1. Bubble Sort Algorithm" << endl;
        cout << "2. Insertion Sort Algorithm" << endl;
        cout << "3. Selection Sort Algorithm" << endl;
        cout << "4. Linear Search Algorithm" << endl;
        cout << "5. Binary Search Algorithm" << endl;
        cout << "Type number: ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Properly discard invalid input
            option = 0;
        }

    } while (option < 1 || option > 5); // Keep looping until a valid option is chosen

    cout << "Enter array size: ";
    cin >> arraySize;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    nums = new int[arraySize];

    for (size_t i = 0; i < arraySize; i++) {
        cout << "Enter value for index " << i << ": ";
        cin >> nums[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (option) {
        case 1:
            bubbleSort(nums, arraySize);
            break;
        case 2:
            insertionSort(nums, arraySize);
            break;
        case 3:
            selectionSort(nums, arraySize);
            break;
        case 4:
            cout << "Enter target you want to search: ";
            cin >> target;
            cout << "Index: " << linearSearch(nums, target, arraySize) << endl;
            break;
        case 5:
            cout << "Enter target you want to search: ";
            cin >> target;
            cout << "Index: " << binarySearch(nums, target, arraySize) << endl;
            break;
    }

    delete[] nums; // Free allocated memory
    return 0;
}
