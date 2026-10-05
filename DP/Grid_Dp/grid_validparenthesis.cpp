https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/?envType=daily-question&envId=2026-09-29


class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != '(' || grid[n-1][m-1] != ')') {
            return false;
        }

        queue<tuple<int, int, int>> q;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(n + m, 0)
            )
        );

        q.push({0, 0, 1});
        dp[0][0][1] = 1;

        while (!q.empty()) {

            auto [i, j, balance] = q.front();
            q.pop();

            // Reached destination
            if (i == n - 1 && j == m - 1 && balance == 0) {
                return true;
            }

            // Move down
            if (i + 1 < n) {

                int newbalance = balance;

                if (grid[i + 1][j] == '(')
                    newbalance++;
                else
                    newbalance--;

                if (newbalance >= 0 &&
                    !dp[i + 1][j][newbalance]) {

                    dp[i + 1][j][newbalance] = 1;

                    q.push({
                        i + 1,
                        j,
                        newbalance
                    });
                }
            }

            // Move right
            if (j + 1 < m) {

                int newbalance = balance;

                if (grid[i][j + 1] == '(')
                    newbalance++;
                else
                    newbalance--;

                if (newbalance >= 0 &&
                    !dp[i][j + 1][newbalance]) {

                    dp[i][j + 1][newbalance] = 1;

                    q.push({
                        i,
                        j + 1,
                        newbalance
                    });
                }
            }
        }

        return false;
    }
};