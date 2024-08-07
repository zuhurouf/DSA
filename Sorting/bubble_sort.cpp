#include <iostream>
#include <vector>

/* Bubble sort: If ith value in an array is greater than (i+1)th value, swap it
                Loop for (n-1) times to sort the array
                For each turn, loop through the array for one less than the turn for swapping
    Time complexity: O(n^2) Two loops passing through each elements and so n*n = n^2
 */

using namespace std;

int main() {
    vector<int> arr = {7, 12, 9, 11, 3};
    int temp;
    bool swapped;
    for (int i = 0; i < 5; i++) {
        swapped = false;
        for (int j = 0; j < 5 - i -1; j++) { //For each ith pass, traverse till (n-i-1)-1 th positoin as the elements after that are already sorted
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    cout << "Sorted array:" << endl;
    for (int elem : arr) {
        cout << elem << ",";
    }
}