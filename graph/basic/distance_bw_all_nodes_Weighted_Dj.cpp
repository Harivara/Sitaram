#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<vector<int>> allPairsShortestPaths(int n, vector<vector<int>>& edges) {
    // Build adjacency list
    vector<vector<Edge>> adj(n);
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int src = 0; src < n; src++) {
        // Min-heap for Dijkstra (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[src][src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[src][u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.to, w = edge.weight;
                if (dist[src][v] > dist[src][u] + w) {
                    dist[src][v] = dist[src][u] + w;
                    pq.push({dist[src][v], v});
                }
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // number of nodes
    vector<vector<int>> edges = {
        {0,1,2}, {0,2,4}, {1,2,1}, {1,3,7}, {2,4,3}, {3,4,1}
    };

    vector<vector<int>> dist = allPairsShortestPaths(n, edges);

    // Print the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 1e9) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
