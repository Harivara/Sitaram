https://leetcode.com/contest/biweekly-contest-161/problems/count-islands-with-total-value-divisible-by-k/description/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, long long& sum, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || grid[row][col] == 0)
            return;

        visited[row][col] = true;
        sum += (long long)grid[row][col];

        // 4 directions: up, right, down, left
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            dfs(newRow, newCol, grid, visited, sum, n, m);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islandCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    long long sum = 0;
                    dfs(i, j, grid, visited, sum, n, m);
                    if (sum % (long long)k == 0) {
                        islandCount++;
                    }
                }
            }
        }

        return islandCount;
    }
};