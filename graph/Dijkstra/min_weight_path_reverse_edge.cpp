https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/

// You consider flipping all the edges incident on a node u and will process them using Dijkstra. 
// After all nodes have been relaxed, while going from 0 to n - 1, from a node you will take only one edge to the next edge, 
// there is no way you will take two distinct edges from the same node that will give you a better answer. 
// Since we'll take only 1 edge, this ensures that atmost 1 switch was done at node u. 
// We just consider flipping all of them to get the optimal answer.

class Solution {
public:
    const int INF = 1e9;

    int minCost(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<pair<int,int>>> graph(n);
        for (auto &edge : edges) {
            int from = edge[0];
            int to   = edge[1];
            int cost = edge[2];

            // Normal edge with given cost
            graph[from].push_back({to, cost});

            // Reverse edge with double the cost
            graph[to].push_back({from, cost * 2});
        }

        // Distance array initialized to INF
        vector<int> dist(n, INF);
        dist[0] = 0;

        // Min-heap for Dijkstra (distance, node)
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});  // (distance, startNode)

        while (!pq.empty()) {
            auto [currentDist, node] = pq.top();
            pq.pop();

            // Skip outdated states
            if (currentDist != dist[node]) continue;    // same nodes have multiple distances skip the outdated ones 

            // If we've reached the target node, return result
            if (node == n - 1) return currentDist;

            // Relax edges
            for (auto &[neighbor, weight] : graph[node]) {
                int newDist = currentDist + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }

        return -1; // No path found
    }
};
