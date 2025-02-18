#include<iostream>

using namespace std;

void insertionSortMethodOne(int arr[], int n){
    int innerCount = 0;
    int count = 0;
    for (size_t i = 0; i < 5; i++)
    {
        count += 1;
        int temp = arr[i];
        for (size_t j = i; j < 5; j++)
        {
            innerCount += 1;
            if (temp > arr[j])
            {
                arr[i] = arr[j];
                arr[j] = temp;
                temp = arr[i];
            }
        }
    }

    cout << "Outer loop count: " << count << endl;
    cout << "Inner loop count: " << innerCount << endl;
}

void insertionSortMethodTwo(int arr[], int n){
    int innerCount = 0;
    int count = 0;
    
    for (size_t i = 1; i < 5; i++)
    {
        count += 1;
        int key = arr[i]; // Assigns the value of the current index to key
        int j = i - 1; // Assigns the value of the previous index to j
        while (j >= 0 && arr[j] > key) // 
        {
            innerCount += 1;
            arr[j + 1] = arr[j]; // Assigns the value of the previous index to the current index
            j = j - 1; // Decrements the value of j by 1
        }
        arr[j + 1] = key; // Assigns the value of key to the current index
    }

    cout << "Outer loop count: " << count << endl;
    cout << "Inner loop count: " << innerCount << endl;
}

int main(){
    int numbers[5] = {2, 2, 2, 1, 3};
    
    insertionSortMethodTwo(numbers, 5);

    cout << "Sorted values\n";
    for (size_t i = 0; i < 5; i++)
    {
        cout << numbers[i] << ", ";
    }
    
    return 0;
}