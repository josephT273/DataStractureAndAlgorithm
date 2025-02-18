#include <iostream>

using namespace std;

int main(){
    int numbers[5];

    for(size_t i = 0; i < 5; i++){
        cout << "Enter number for index " << i << ": ";
        cin >> numbers[i];
    }

    cout << "User given values\n";
    for(size_t i = 0; i < 5; i++){
        cout << numbers[i] << ", ";
    }
    return 0;
}