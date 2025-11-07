https://leetcode.com/problems/longest-increasing-path-in-a-matrix/?envType=problem-list-v2&envId=graph

class Solution {
public:
    int n, m;

    bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& lip) {
        if (lip[i][j] != 0) return lip[i][j]; // already computed

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        int best = 1; // at least the cell itself
        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (check(nrow, ncol) && matrix[nrow][ncol] > matrix[i][j]) {
                best = max(best, 1 + dfs(nrow, ncol, matrix, lip));
            }
        }

        lip[i][j] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> lip(n, vector<int>(m, 0));

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, dfs(i, j, matrix, lip));
            }
        }
        return maxi;
    }
};
