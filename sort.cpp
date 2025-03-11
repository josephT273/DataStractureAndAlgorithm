#include<iostream>

using namespace std;

void selectionSort(int numbers[], int n){
    for(size_t i = 0; i < n; i++){
        int smallestIndex = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (numbers[smallestIndex] > numbers[j])
            {
                smallestIndex = j;
            }
        }
        swap(numbers[smallestIndex], numbers[i]);
    }

    cout << "\nSelection sort\n";
    for(size_t i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }
}

void insertionSort(int numbers[], int n){
    for (int i = 1; i < n; i++) {
        int temp = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > temp) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = temp;
    }

    cout << "\nInsertion sort result:\n";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int numbers[], int n){
    bool swaped = false;
    for(size_t i = 0; i < n - 1; i++){
        for (size_t j = 0; j < n - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                swap(numbers[j], numbers[j + 1]);
                swaped = true;
            }
        }

        if (!swaped)
        {
            break;
        }
    }
    cout << endl << "Bubble sort\n";
    for(size_t i = 0; i < n; i++){
        cout << numbers[i] << " ";
    }
}
int main(){
    int numbers[5] = {-2, 3, -1, 0, 5};

    selectionSort(numbers, 5);
    insertionSort(numbers, 5);
    bubbleSort(numbers, 5);
    
    return 0;
}