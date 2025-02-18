#include<iostream>

using namespace std;

void insertionSortMethodOne(int arr[], int n){
    for (size_t i = 0; i < 5; i++)
    {
        int temp = arr[i];
        for (size_t j = i; j < 5; j++)
        {
            if (temp > arr[j])
            {
                arr[i] = arr[j];
                arr[j] = temp;
                temp = arr[i];
            }
        }
    }
}

void insertionSortMethodTwo(int arr[], int n){
    for (size_t i = 1; i < 5; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int numbers[5] = {2, 2, 2, 1, 3};
    
    insertionSortMethodOne(numbers, 5);

    cout << "Sorted values\n";
    for (size_t i = 0; i < 5; i++)
    {
        cout << numbers[i] << ", ";
    }
    
    return 0;
}