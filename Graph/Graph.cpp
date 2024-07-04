#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    char connect;
    cout << "Number of vertices: ";
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "Connect " << i+1 << " and " << j+1 << " (y/n)?";
                cin >> connect;
                if (connect == 'y') {
                    edges[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << edges[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}