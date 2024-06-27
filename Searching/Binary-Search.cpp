#include <iostream>
#include <vector>

using namespace std;


int merge_sort(vector<int>& arr, int key, int low, int high) {
    int mid = low + (high - low) / 2;
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


int main() {
    vector<int> arr = {10, 14, 19, 27, 33, 35, 42, 44, 56};
    int key = 42, low = 0, high = arr.size() - 1;
    cout << key << ":" << merge_sort(arr, key, low, high) << endl;
    return 0;
}