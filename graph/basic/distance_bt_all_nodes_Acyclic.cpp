// DFS+Topological sort

#include <bits/stdc++.h>
using namespace std;

void topoDFS(int u, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (auto& [v, w] : adj[u]) {
        if (!visited[v]) topoDFS(v, adj, visited, st);
    }
    st.push(u);
}

vector<int> shortestPathDAG(int n, vector<vector<int>>& edges, int src) {
    vector<vector<pair<int,int>>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
    }

    // Step 1: Topological Sort
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) topoDFS(i, adj, visited, st);
    }

    // Step 2: Relax edges in topological order
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (dist[u] != 1e9) {
            for (auto& [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    return dist;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {
        {0,1,5}, {0,2,3}, {1,3,6}, {1,2,2}, 
        {2,4,4}, {2,5,2}, {2,3,7}, {3,4,-1}, {4,5,-2}
    };

    vector<int> dist = shortestPathDAG(n, edges, 1);

    for (int i = 0; i < n; i++) {
        if (dist[i] == 1e9) cout << "INF ";
        else cout << dist[i] << " ";
    }
}
