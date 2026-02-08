class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while (!pq.empty()) {
            auto [cost, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if (x == n-1 && y == m-1)
                return cost;
            
            if (cost > dist[r][c]) continue;


            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newCost = cost + grid[nx][ny];
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
