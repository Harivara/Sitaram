https://leetcode.com/problems/minimize-maximum-component-cost/description/

class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y) {
            int xr = find(x);
            int yr = find(y);
            if (xr == yr) {
                return false;
            }
            if (rank[xr] > rank[yr]) {
                parent[yr] = xr;
            } else if (rank[xr] < rank[yr]) {
                parent[xr] = yr;
            } else {
                parent[xr] = yr;
                rank[yr]++;
            }
            return true;
        }
    };
    int minCost(int n, vector<vector<int>>& edges, int k) {

        if (k > n)
            return -1;
        // sort(edges.begin(),edges.end(), [](vector<int>&a,vector<int>&b){
        //     return a[2]<b[2];
        // });
        // DSU dsu(n);

        // vector<int>mts_weights;
        // for(auto &e:edges){
        //     if(dsu.unite(e[0],e[1])){
        //         mts_weights.push_back(e[2]);
        //     }
        // }
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<int> visited(n, 0);
        vector<int> mts_weights;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty() && mts_weights.size() < n - 1) {
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (visited[u] == 1) {
                continue;
            }
            visited[u] = true;

            // Skip adding the 0th node's dummy weight (first picked node)
            if (u != 0) {
                mts_weights.push_back(w);
            }
            for (auto& [v, wt] : graph[u]) {
                if (visited[v] == 0) {
                    pq.push({wt, v});
                }
            }
        }

        int remove_edges = k - 1;
        if (mts_weights.size() < remove_edges) {
            return -1;
        } else if (mts_weights.size() == remove_edges) {
            return 0;
        }
        // Sort descending and skip the first (k-1) largest edges
        sort(mts_weights.begin(), mts_weights.end(), greater<int>());
        for (int i = 0; i < mts_weights.size(); i++) {
            cout << mts_weights[i] << " ";
        }
        return mts_weights[remove_edges];
    }
};©leetcode