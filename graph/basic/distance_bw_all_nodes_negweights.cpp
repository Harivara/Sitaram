// If your graph is directed + weighted(negative), you should use:// Floyd–Warshall (if graph is small, n ≤ 400).
also used for detecting cycles dist[i][j]<0

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> floydWarshall(int n, vector<vector<int>>& edges) {
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distance to self = 0
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    // Fill edges
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w); // if undirected
    }

    // Floyd–Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {0,1,5}, {0,2,9}, {1,2,2}, {2,3,3}
    };

    vector<vector<int>> dist = floydWarshall(n, edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
