#include <iostream>
#include <vector>
using namespace std;

// Partition function: Places the pivot in its correct position
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than the pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the index of the pivot
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Unsorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
