#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    // Initialize Union-Find for n vertices (0 to n-1)
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return; // Already in same set

        if (rank[rootX] < rank[rootY])
            swap(rootX, rootY);

        parent[rootY] = rootX;
        if (rank[rootX] == rank[rootY])
            rank[rootX]++;
    }

    // Optional: check if two nodes are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n = 5; // number of vertices
    UnionFind uf(n);

    uf.unite(0, 1);
    uf.unite(1, 2);

    cout << "Are 0 and 2 connected? " << (uf.connected(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 3 and 4 connected? " << (uf.connected(3, 4) ? "Yes" : "No") << endl;

    uf.unite(3, 4);
    cout << "Are 3 and 4 connected now? " << (uf.connected(3, 4) ? "Yes" : "No") << endl;

    return 0;
}
