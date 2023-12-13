#include <iostream>

using namespace std;

void bubbleSortAscending(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSortAscending(int arr[], int n) {
    int ind;
    for(int i = 0; i < n - 1; i++){
        ind = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j]< arr[ind]){
                swap(arr[ind], arr[j]);
            }
        }
    }
}

int sequentialSearch1D(int arr[], int n, int x) {
    for(int i =0; i<n; i++){
        if(arr[i]==x){
            return i;
        }
        return -1;
    }
}

bool sequentialSearch2D(int arr[][5], int rows, int cols, int x) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j]==x){
                cout << "element found: row " << i << " column: " << j << endl;
                return true;
            }
        }
    }
    return false;
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSortAscending(arr,n);
    printArray(arr, n);

    int arr1D[] = {2, 4, 7, 10, 15};
    int n1D = sizeof(arr1D) / sizeof(arr1D[0]);
    int x; // Element to search for in 1D array

    cout << "Enter the element to search for in the 1D array: ";
    cin >> x;
    cout << sequentialSearch1D(arr1D, n1D, x);

    return 0;
}