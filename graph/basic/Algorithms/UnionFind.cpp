https://leetcode.com/problems/minimum-time-for-k-connected-components/description/

class Dsu {
public:
    vector<int> parent;
    vector<int> rank;

    Dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool unite(int a, int b) {       // focus here, a bit change than usual.
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa == pb) return false;

        if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
        return true;
    }
};

class Solution {
public:

// Main Logic:-

/* Think in reverse:
Since edges are removed over time, and the graph breaks apart, you want to start from a fully disconnected graph and add back edges in descending time order,keeping only those with time>t.

At every time step, simulate what happens if you don’t remove the edge (i.e., time > t), and track when the number of connected components drops below k.

*/
    int minTime(int n, vector<vector<int>>& edges, int k) {
        // Sort by descending time
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        Dsu dsu(n);
        int components = n;

        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            if (dsu.unite(u, v)) { // ultimate parent are not same so, they will unite and hence the no. of components will reduce.
                components--;
            }
            if (components < k) {
                return t;
            }
        }

        // If even after removing all edges we have ≥ k components
        return 0;
    }
};