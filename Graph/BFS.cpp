#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void display(int n, vector<vector<int>>& adj_mat) {
    cout << "Displaying adjecency matrix" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << "\n";
    }
}


void bfs(int n, int start, vector<vector<int>>& adj_mat) {
    int pop_elem;
    vector<int> queue, visited;
    
    queue.push_back(start);
    while (!queue.empty()) {
        pop_elem = queue[0];
        queue.erase(queue.begin());
        cout << pop_elem << endl;
        visited.push_back(pop_elem);
        for (int i = 1; i <= n; i++) {
            if ((adj_mat[pop_elem][i] == 1) && (find(visited.begin(), visited.end(), i) == visited.end()) && (find(queue.begin(), queue.end(), i) == queue.end())) {
                queue.push_back(i);
            }
        }
    }
}


int main() {
    int n, start;
    char connect;
    cout << "Number of vertices: ";
    cin >> n;
    vector<vector<int>> adj_mat(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "Connect " << i+1 << " and " << j+1 << " (y/n)?";
                cin >> connect;
                if (connect == 'y') {
                    adj_mat[i][j] = 1;
                }
            }
        }
    }
    display(n, adj_mat);
    cout << "Start from? ";
    cin >> start;
    bfs(n, start, adj_mat);
    return 0;
}
