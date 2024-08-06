// divide and conquer algorithm
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// tc: o(nlogn)
// sc: o(1)

int partition (int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high){
            i++;
        }
        while(arr[j] > pivot && j >= low){
            j--; 
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high){
        int partitionIdx = partition(arr, low, high);
        quickSort(arr, low, partitionIdx-1);
        quickSort(arr, partitionIdx+1, high);
    }
}

int main() {

    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Before Quick sort Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    quickSort(arr, 0, n - 1);
    cout << "After Quick sort Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}