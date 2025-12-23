#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // comment this if graph is directed
    }

    vector<int> visited(n, 0);

    cout << "DFS traversal: ";
    dfs(0, graph, visited); // starting DFS from node 0
    cout << endl;

    return 0;
}
