#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    // Min-heap: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        // Skip if we’ve already found a better path
        if (current_distance > dist[current_vertex]) continue;

        for (auto& edge : graph[current_vertex]) {
            int neighbor = edge.first;
            int weight = edge.second;

            int distance = current_distance + weight;
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                pq.push({distance, neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // remove this line if the graph is directed
    }

    int start;
    cin >> start;

    vector<int> distances = dijkstra(start, graph);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INT_MAX)
            cout << i << ": INF\n";
        else
            cout << i << ": " << distances[i] << "\n";
    }

    return 0;
}
