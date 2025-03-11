#include<iostream>
#include<algorithm>

using namespace std;

int linearSearch(int arr[], int arrSize, int target){
    for (size_t i = 0; i < arrSize; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int binarySort(int arr[], int arrSize, int target) {
    int low = 0;
    int high = arrSize - 1;
    int mid;
    int value = -1;
    int* sortedArr = new int[arrSize];

    for(int i = 0; i < arrSize; i++){
        sortedArr[i] = arr[i];
    }

    sort(sortedArr, sortedArr + arrSize);

    while (low <= high) {
        mid = (high + low) / 2;

        if (sortedArr[mid] == target) {
            delete[] sortedArr;
            return mid;
        } else if (sortedArr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    delete[] sortedArr;
    return -1;
}


int main(){
    int numbers[5] = {4, 2, 6, 1, 8};
    // int algo = linearSearch(numbers, 5, 5);
    int algo = binarySort(numbers, 5, 1);
    
    if(algo == -1){
        cout << "Key not found\n";
    }else{
        cout << "Key found on index: " << algo << endl;
    }
    return 0;
}