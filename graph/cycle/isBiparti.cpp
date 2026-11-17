// https://leetcode.com/problems/is-graph-bipartite

// why to return false when dfs is true?

// 1. What does DFS return?
// In our implementation:
// - dfs() == true → We found a conflict (two adjacent nodes have the same depth parity).
// - dfs() == false → No conflict was found in that DFS traversal.
// So, dfs() returning true actually means the graph is NOT bipartite.


class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& visited, vector<int>& depth) {

        visited[node] = 1;

        for(int i = 0; i < graph[node].size(); i++) {

            int adj = graph[node][i];

            if(visited[adj] == 0) {
                depth[adj] = depth[node] + 1;

                if(dfs(adj, graph, visited, depth)) {
                    return true;
                }
            }
            else if(depth[adj] % 2 == depth[node] % 2) {
                return true;
            }
        }

        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> visited(n, 0);
        vector<int> depth(n, 0);

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                if(dfs(i, graph, visited, depth)) {
                    return false;
                }
            }
        }

        return true;
    }
};
