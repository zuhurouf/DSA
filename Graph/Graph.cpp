#include <iostream>
#include <vector>

using namespace std;


void display(int n, vector<vector<int>>& edges) {
    cout << "Displaying adjecency matrix" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << edges[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {
    int n, opt, n1, n2;
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
    display(n, edges);
    
    
    while (true) {
        cout << "1. Add a vertex\n2. Add an edge\n3. Remove an edge" << endl;
        cin >> opt;
        switch (opt) {
            case 1:
                n += 1;
                edges.resize(n);
                for (auto& row: edges) {
                    row.resize(n, 0);
                }
                // edges[n][i]
                for(int i = 0; i < n; i++) {
                    if (i != n-1) {
                        cout << "Connect " << n << " and " << i+1 << "(y/n)?";
                        cin >> connect;
                        if (connect == 'y') {
                            edges[n-1][i] = 1;
                        }
                    }
                }
                // edges[i][n]
                for(int i = 0; i < n; i++) {
                    if (i != n-1) {
                        cout << "Connect " << i+1 << " and " << n << "(y/n)?";
                        cin >> connect;
                        if (connect == 'y') {
                            edges[i][n-1] = 1;
                        }
                    }
                }
                display(n, edges);
                break;
            
            case 2:
                cout << "Create an edge between: ";
                cin >> n1 >> n2;
                if (edges[n1 - 1][n2 - 1] != 1) {
                    edges[n1 - 1][n2 - 1] = 1;
                    display(n, edges);
                }
                else {
                    cout << "There is an edge between " << n1 << " and " << n2 << endl;
                }
                break;
            
            case 3:
                cout << "Remove an edge between: ";
                cin >> n1 >> n2;
                if (edges[n1 - 1][n2 - 1] == 1) {
                    edges[n1 - 1][n2 - 1] = 0;
                    display(n, edges);
                }
                else {
                    cout << "There  is no edge between " << n1 << " and " << n2 << endl;
                }
                break;
            
            default:
                display(n, edges);
                break;
        }
    }
    return 0;
}
