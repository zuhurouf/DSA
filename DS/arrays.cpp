#include <iostream>
#include <vector>

using namespace std;


int get_min(vector<int>& arr) {
    int min = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}


int get_max(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}


int find(vector<int>& arr, int elem) {
    int pos = -1;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == elem) {
            pos = i;
            break;
        }
    }
    return pos;
}


void display(vector<int>& arr) {
    for (int elem : arr) {
        cout << elem << " ";
    }
}


void insert(vector<int>& arr, int elem, int pos) {
    arr.insert(arr.begin() + pos, elem);
    display(arr);
}


void delete_elem(vector<int>& arr, int pos) {
    arr.erase(arr.begin() + pos);
    display(arr);
}


int main() {
    vector<int> arr;
    int n, elem, pos;

    cout << "Size of the array: ";
    cin >> n;
    cout << "Enter array elements:" << endl;
    for (int i = 0; i <n; i++) {
        cin >> elem;
        arr.push_back(elem);
    }

    // Traversing the array
    cout << "Elements of array" << endl;
    display(arr);

    // Find the position of an element
    cout << "\nFind: ";
    cin >> elem;
    cout << "Position of " << elem << " is " << find(arr, elem) << endl;

    // Inserting an element
    cout << "Insert data: ";
    cin >> elem;
    cout << "Insert at: ";
    cin >> pos;
    insert(arr, elem, pos);

    // Deleting an elemet
    cout << "\nDelete element at position: ";
    cin >> pos;
    delete_elem(arr, pos);


    // Minimum and maximum element in an array
    cout << "\nMinimum: " << get_min(arr) << endl;
    cout << "Maximum: " << get_max(arr) << endl;

    return 0;
}