#include<iostream>
using namespace std;

int findPeak(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2;
    
    // Check if mid is a peak
    if ((mid == 0 || arr[mid] >= arr[mid - 1]) && 
        (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
        return mid;
    }
    // If left neighbor is greater, search left half
    else if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeak(arr, low, mid - 1, n);
    }
    // Else search right half
    else {
        return findPeak(arr, mid + 1, high, n);
    }
}

int main() {
    int arr[] = {4, 7, 8, 1, 0, 4, 3, 2, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = findPeak(arr, 0, n - 1, n);
    cout << "Peak found at index: " << peakIndex << " (Value: " << arr[peakIndex] << ")";
    return 0;
}