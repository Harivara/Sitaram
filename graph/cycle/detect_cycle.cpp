#include <bits/stdc++.h>
using namespace std;

// DFS helper function to detect cycle
bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            // Found a back edge → cycle detected
            return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

// Main function to check for cycle
bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack))
                return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // directed edge u -> v
    }

    if (hasCycle(graph))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}

// --------------------------------------UNDIRECTED GRAPH -----------------------------

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    for (int nbr : adj[node]) {
        if (!vis[nbr]) {
            if (dfs(nbr, node, adj, vis))
                return true;
        } else if (nbr != parent) {
            return true; // cycle detected
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}
