#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number){
    // must be greater than 1
    if (number <= 1) {
        return false; 
    }
    // test for prime
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

void bubbleSortAscending(int arr[], int length) {
    // bubble sort algorithm do bit by bit
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

main(){
    // origional vector 
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    // array for only prime number
    int pArray[n];
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(arr[i])) {
            pArray[x] = arr[i];
            x++;
        }
    }
    int size = sizeof(pArray)/sizeof(pArray[0]);
    // calling thge functions
    bubbleSortAscending(pArray,size);
    printArray(pArray, x);

    return 0;
}