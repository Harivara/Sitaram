#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int primMST(int n, vector<vector<pair<int, int>>>& graph) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int totalCost = 0;
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalCost += weight;

        for (auto& [v, w] : graph[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    return totalCost;
}
