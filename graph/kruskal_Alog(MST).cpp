class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;

        if (rank[xr] < rank[yr]) parent[xr] = yr;
        else if (rank[xr] > rank[yr]) parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

int kruskalMST(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];  // sort by weight
    });

    DSU dsu(n);
    int mst_weight = 0;
    int count = 0;

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dsu.unite(u, v)) {
            mst_weight += w;
            count++;
            if (count == n - 1) break;
        }
    }

    return mst_weight;
}
