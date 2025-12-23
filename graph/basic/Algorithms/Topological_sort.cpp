#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int>& visited, stack<int>& st) {
    visited[node] = 1;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, st);
        }
    }

    // Push current node after visiting all its neighbors
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    int n, m;
    cin >> n >> m; // n = vertices, m = edges

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed edge u → v
    }

    vector<int> topo = topologicalSort(graph);

    cout << "Topological order: ";
    for (int node : topo) cout << node << " ";
    cout << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSortBFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indegree(n, 0);

    // Step 1: Compute indegree of each node
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }

    // Step 2: Push all nodes with indegree 0 into queue
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    // Step 3: Process queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // Decrease indegree of neighbors
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Step 4: Check for cycle (if not all nodes processed)
    if ((int)topo.size() != n) {
        cout << "Cycle detected! Topological sort not possible.\n";
        return {};
    }

    return topo;
}

int main() {
    int n, m;
    cin >> n >> m; // number of vertices, edges

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed edge u -> v
    }

    vector<int> topo = topologicalSortBFS(graph);

    if (!topo.empty()) {
        cout << "Topological order: ";
        for (int node : topo) cout << node << " ";
        cout << endl;
    }

    return 0;
}
