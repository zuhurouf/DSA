#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> arr = {10, 14, 19, 27, 33, 35, 42, 44, 56};
    int pos = -1;
    // Test Case 1: First element as key
    // int key = 10;
    // Test Case 2: Last element as key
    // int key = 56;
    // Test Case 3: Any element in the middle of array as key
    // int key = 35;
    // Test Case 4: Non-existent element as key
    int key = 89;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }

    cout << "Posiiton of " << key << " is " << pos << endl;
    return 0;
}