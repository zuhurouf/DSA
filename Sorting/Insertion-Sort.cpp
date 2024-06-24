#include <iostream>
#include <vector>

using namespace std;


int main() {
    // Test Case 1: Ascending order array
    // vector<int> arr = {3, 7, 9, 11, 12};
    
    // Test Case 2: Descending order arra
    //vector<int> arr = {12, 11, 9, 7, 3};

    // Test Case 3: Unsorted array
    vector<int> arr = {7, 12, 9, 11, 3};
    int j, key, arr_size = arr.size();
    
    for (int i = 1; i < arr_size; i++) {
        key = arr[i];
        j = i;
        while (j >= 0 and arr[j-1] > key) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }

    for (int e : arr) {
        cout << e << " ";
    }
}