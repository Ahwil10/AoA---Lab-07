#include <iostream>
#include <vector>

using namespace std;

// Function to maintain the max-heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap them and recursively heapify the affected sub-tree
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from the array
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    // Start from the last non-leaf node and move backwards up to the root (index 0)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    // A random, unsorted array
    vector<int> arr = {4, 10, 3, 5, 1, 9, 2};

    cout << "Original array:\n";
    printArray(arr);

    // Transform into a Max-Heap
    buildMaxHeap(arr);

    cout << "\nArray transformed into a Max-Heap:\n";
    printArray(arr);

    return 0;
}
