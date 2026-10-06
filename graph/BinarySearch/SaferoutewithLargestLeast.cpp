https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2026-07-01

class Solution {
public:
    int n, m;
    int drow[4] = {0, 1, 0, -1};
    int dcol[4] = {1, 0, -1, 0};

    bool feasible(int val, vector<vector<int>>& dist) {
        if (dist[0][0] < val)
            return false;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !vis[nr][nc] &&
                    dist[nr][nc] >= val) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
    if(grid[0][0] ==1 || grid[n-1][m-1]==1){
        return 0;
    }
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        int low = 0;
        int high = 2 * (n - 1);
        int ans = 0;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (!feasible(mid, dist)) {
                high=mid;
            } else {
                low=mid+1;
            }
        }

        return low-1;
    }
};