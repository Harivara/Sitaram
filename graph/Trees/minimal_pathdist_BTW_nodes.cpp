https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths-ii/
// // #include <bits/stdc++.h>
// // using namespace std;

// // class Solution {
// // public:
// //     const int INF = 1e9;

// //     vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& graph, int n) {
// //         vector<int> dist(n, INF);
// //         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
// //         pq.push({0, src});
// //         dist[src] = 0;

// //         while (!pq.empty()) {
// //             auto [d, u] = pq.top(); pq.pop();
// //             if (d > dist[u]) continue;

// //             for (auto &[v, w] : graph[u]) {
// //                 if (dist[v] > d + w) {
// //                     dist[v] = d + w;
// //                     pq.push({dist[v], v});
// //                 }
// //             }
// //         }

// //         return dist;
// //     }

// //     vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
// //         int n = 0;
// //         for (auto &e : edges) {
// //             n = max(n, max(e[0], e[1]));
// //         }
// //         n += 1;

// //         vector<vector<pair<int, int>>> graph(n);
// //         for (auto &e : edges) {
// //             int u = e[0], v = e[1], w = e[2];
// //             graph[u].emplace_back(v, w);
// //             graph[v].emplace_back(u, w);
// //         }

// //         vector<int> res;
// //         for (auto &q : queries) {
// //             int s1 = q[0], s2 = q[1], dest = q[2];

// //             vector<int> d1 = dijkstra(s1, graph, n);
// //             vector<int> d2 = dijkstra(s2, graph, n);
// //             vector<int> d3 = dijkstra(dest, graph, n);

// //             int ans = INF;
// //             for (int i = 0; i < n; ++i) {
// //                 if (d1[i] < INF && d2[i] < INF && d3[i] < INF) {
// //                     ans = min(ans, d1[i] + d2[i] + d3[i]);
// //                 }
// //             }
// //             res.push_back(ans == INF ? -1 : ans);
// //         }

// //         return res;
// //     }
// // };


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     const int INF = 1e9;

//     vector<int> dijkstra(int src, const vector<vector<pair<int, int>>>& graph, int n) {
//         vector<int> dist(n, INF);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//         pq.push({0, src});
//         dist[src] = 0;

//         while (!pq.empty()) {
//             auto [d, u] = pq.top(); pq.pop();
//             if (d > dist[u]) continue;

//             for (auto &[v, w] : graph[u]) {
//                 if (dist[v] > d + w) {
//                     dist[v] = d + w;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }
//         return dist;
//     }

//     vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
//         int n = 0;
//         for (auto &e : edges) {
//             n = max(n, max(e[0], e[1]));
//         }
//         n += 1;

//         vector<vector<pair<int, int>>> graph(n);
//         for (auto &e : edges) {
//             int u = e[0], v = e[1], w = e[2];
//             graph[u].emplace_back(v, w);
//             graph[v].emplace_back(u, w);
//         }

//         // Step 1: Collect all unique nodes from queries
//         unordered_set<int> nodesToRunDijkstra;
//         for (auto &q : queries) {
//             nodesToRunDijkstra.insert(q[0]); // src1
//             nodesToRunDijkstra.insert(q[1]); // src2
//             nodesToRunDijkstra.insert(q[2]); // dest
//         }

//         // Step 2: Run Dijkstra only once per unique node
//         unordered_map<int, vector<int>> distFrom;
//         for (int node : nodesToRunDijkstra) {
//             distFrom[node] = dijkstra(node, graph, n);
//         }

//         // Step 3: Process each query using precomputed distances
//         vector<int> res;
//         for (auto &q : queries) {
//             int s1 = q[0], s2 = q[1], dest = q[2];
//             int ans = INF;

//             for (int mid = 0; mid < n; ++mid) {
//                 int d1 = distFrom[s1][mid];
//                 int d2 = distFrom[s2][mid];
//                 int d3 = distFrom[dest][mid];
//                 if (d1 < INF && d2 < INF && d3 < INF) {
//                     ans = min(ans, d1 + d2 + d3);
//                 }
//             }

//             res.push_back(ans == INF ? -1 : ans);
//         }

//         return res;
//     }
// };

class Solution {
    static const int LOG = 17;
    vector<vector<pair<int, int>>> tree;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> dist;

    void dfs(int u, int p) {
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) {+
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (auto &[v, w] : tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dist[v] = dist[u] + w;
                dfs(v, u);
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; ++i) {
            if (diff & (1 << i)) u = up[u][i];
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    long long getDist(int u, int v) {
        int ancestor = lca(u, v);
        return dist[u] + dist[v] - 2 * dist[ancestor];
    }

public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        tree.assign(n, {});
        up.assign(n, vector<int>(LOG));
        depth.assign(n, 0);
        dist.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }

        dfs(0, 0);  // Root at node 0

        vector<int> result;
        for (auto &q : queries) {
            int a = q[0], b = q[1], c = q[2];
            long long total = getDist(a, b) + getDist(b, c) + getDist(c, a);
            result.push_back((int)(total / 2));  // divide by 2 to get unique path cost
        }

        return result;
    }
};
