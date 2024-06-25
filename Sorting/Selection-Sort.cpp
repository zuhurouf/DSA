#include <iostream>
#include <vector>


using namespace std;


int main() {
    // Test Case 1: Sorted array (ascending)
    // vector<int> arr = {3, 7, 9, 11, 12};
    // Test Case 2: Unsorted array (descending)
    // Test Case 3: Unsorted array
    vector<int> arr = {12, 11, 9, 7, 3};
    //vector<int> arr = {7, 12, 9, 11, 3};
    int temp, min_pos, arr_size = arr.size();

    cout << "Before" << endl;
    for (int e: arr) {
        cout << e << " ";
    }

    for (int i = 0; i < arr_size; i++) {
        min_pos = i;
        for (int j = i+1; j < arr_size; j++) {
            if (arr[j] < arr[min_pos]) {
                min_pos = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = temp;
    }

    cout << "\nAfter" << endl;
    for (int e: arr) {
        cout << e << " ";
    }
    return 0;
}