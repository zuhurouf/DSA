#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    vector<int> arr = {10, 14, 19, 27, 33, 35, 42, 44, 56};
    int block = sqrt(arr.size()) - 1, pos = -1, i = 0;
    // Test Case 0: First element
    int key = 10;
    // Test Case 1: First element of a block
    // int key = 27;
    // Test Case 2: An element in anywhere of a block
    // int key = 35;
    // Test Case 3: Last element
    // int key = 56;
    while (arr[i] < key) {
        i += block;
    }
    
    for (int j = i; j >= 0; j--) {
        if (arr[j] == key) {
            pos = j;
            break;
        }
    }

    cout << "Position of " << key << " is " << pos << endl;
    return 0;
}