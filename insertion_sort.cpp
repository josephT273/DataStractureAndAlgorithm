#include<iostream>

using namespace std;

void insertionSort(int arr[], int n){
    int innerCount = 0;
    int count = 0;
    int j, key;
    for (size_t i = 1; i < 5; i++)
    {
        count += 1;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            innerCount += 1;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout << "Outer loop count: " << count << endl;
    cout << "Inner loop count: " << innerCount << endl;
}


int main(){
    int numbers[5] = {1, 5, 2, 4, 3};
    int j, key;

    insertionSort(numbers, 5);
    

    cout << "Sorted values\n";
    for (size_t i = 0; i < 5; i++)
    {
        cout << numbers[i] << ", ";
    }
    
    return 0;
}