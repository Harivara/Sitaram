https://www.interviewbit.com/problems/useful-extra-edges/

int Solution::solve(
    int A,
    vector<vector<int>> &B,
    int C,
    int D,
    vector<vector<int>> &E
) {
    vector<int> dist1(A + 1, INT_MAX);
    vector<int> dist2(A + 1, INT_MAX);

    // Build adjacency list
    vector<vector<pair<int,int>>> adj(A + 1);
    for (auto &edge : B) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dijkstra = [&](int src, vector<int> &dist) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;  // this is to remove cases where the dist is calculated using the previously poped out elements

            for (auto &e : adj[node]) {
                int nei = e.first;
                int w = e.second;
                if (dist[nei] > d + w) {
                    dist[nei] = d + w;
                    pq.push({dist[nei], nei});
                }
            }
        }
    };

    // Run Dijkstra from C and D
    dijkstra(C, dist1);
    dijkstra(D, dist2);

    int ans = dist1[D];  // without extra edge

    // Try using one extra edge
    for (auto &e : E) {
        int u = e[0], v = e[1], w = e[2];

        if (dist1[u] != INT_MAX && dist2[v] != INT_MAX)
            ans = min(ans, dist1[u] + w + dist2[v]);

        if (dist1[v] != INT_MAX && dist2[u] != INT_MAX)
            ans = min(ans, dist1[v] + w + dist2[u]);
    }

    return (ans == INT_MAX ? -1 : ans);
}
