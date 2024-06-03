#include <iostream>
#include <chrono>

using namespace std;


int fibonacci_for(int n) {
    int sum, opr1 = 0, opr2 = 1;
    if (n <= 1) {
        return n;
    }
    else {
        for (int i = 0; i <= n; i++) {
            sum = opr1 + opr2;
            opr1 = opr2;
            opr2 = sum;
        }
        return sum;
    }
}


int fibonacci_rec(int n) {
    int opr1 = 0, opr2 = 1, sum = 0;
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci_rec(n - 2) + fibonacci_rec(n - 1);
    }
}


int main() {
    cout << "Recurssive function" << endl;
    //TC 1: n = 0
    auto start = chrono::high_resolution_clock::now();
    cout << "For n = 0: " << fibonacci_rec(0) << endl;
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Time taken: " << duration.count() << endl;

    //TC 2: n = 1
    start = chrono::high_resolution_clock::now();
    cout << "For n = 1: " << fibonacci_rec(1) << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken: " << duration.count() << endl;

    //TC 3: n = 10
    start = chrono::high_resolution_clock::now();
    cout << "For n = 10: " << fibonacci_rec(10) << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken: " << duration.count() << endl;

    //TC 3: n = 50
    start = chrono::high_resolution_clock::now();
    cout << "For n = 50: " << fibonacci_rec(50) << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken: " << duration.count() << endl;


    cout << "For loop" << endl;
    //TC 1: n = 0
    start = chrono::high_resolution_clock::now();
    cout << "For n = 0: " << fibonacci_for(0) << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken: " << duration.count() << endl;

    //TC 2: n = 1
    start = chrono::high_resolution_clock::now();
    cout << "For n = 1: " << fibonacci_for(1) << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken: " << duration.count() << endl;

    //TC 3: n = 10
    start = chrono::high_resolution_clock::now();
    cout << "For n = 10: " << fibonacci_for(10) << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken: " << duration.count() << endl;

    //TC 4: n = 50
    start = chrono::high_resolution_clock::now();
    cout << "For n = 0: " << fibonacci_for(50) << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken: " << duration.count() << endl;
}