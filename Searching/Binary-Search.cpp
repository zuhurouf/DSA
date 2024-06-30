#include <iostream>
#include <vector>

using namespace std;


int merge_sort(vector<int>& arr, int key, int low, int high) {
    int mid = low + (high - low) / 2;
    if (high < low) {
        return -1;
    }
    else {
        if (key == arr[mid]) {
        return mid;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
            return merge_sort(arr, key, low, high);
        }
        else {
            low = mid + 1;
            return merge_sort(arr, key, low, high);
        }
    }
}


int main() {
    vector<int> arr = {10, 14, 19, 27, 33, 35, 42, 44, 56};
    int low = 0, high = arr.size() - 1;
    // Test Case 1: Key in the left end of array
    // int key = 14;
    // Test Case 2: Key in the right end of array
    // int key = 42;
    // Test Case 3: Key in the middle of the array
    // int key = 33;
    // Test Case 4: Key not in the array
    int key = 98;
    cout << "Position of " << key << " is " << merge_sort(arr, key, low, high) << endl;
    return 0;
}