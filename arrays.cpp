#include <iostream>
#include <vector>

using namespace std;


int find(vector<int> arr, int elem) {
    int pos = -1;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == elem) {
            pos = i;
            break;
        }
    }
    return pos;
}


int get_min(vector<int> arr) {
    int min = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}


int get_max(vector<int> arr) {
    int max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    vector<int> arr;
    int n, elem;

    cout << "Size of the array: ";
    cin >> n;
    cout << "Enter array elements:" << endl;
    for (int i = 0; i <n; i++) {
        cin >> elem;
        arr.push_back(elem);
    }
    cout << "Elements of array" << endl;
    for(int elem : arr) {
        cout << elem << ",";
    }
    cout << "Find: ";
    cin >> elem;
    cout << "\nPositoin of " << elem << " is " << find(arr, elem) << endl;
    cout << "Minimum: " << get_min(arr) << endl;
    cout << "Maximum: " << get_max(arr) << endl;

    return 0;
}