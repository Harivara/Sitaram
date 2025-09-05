// Complexity: O(V * (V + E))

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPairsDistances(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected
    }
    
    vector<vector<int>> dist(n, vector<int>(n, -1));

    for (int src = 0; src < n; src++) {
        queue<int> q;
        dist[src][src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[src][v] == -1) {
                    dist[src][v] = dist[src][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{0,4}};
    
    vector<vector<int>> dist = allPairsDistances(n, edges);

    // Print distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
