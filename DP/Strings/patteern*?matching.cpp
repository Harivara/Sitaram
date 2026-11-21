
class Solution {
public:

    int solve(int i, int j, string &text, string &mask,
              vector<vector<int>>& dp) {

        if (i < 0 && j < 0)
            return true;

        if (j < 0)
            return false;

        if (i < 0) {
            // Remaining pattern must contain only '*'
            for (int k = 0; k <= j; k++) {
                if (mask[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (mask[j] == text[i] || mask[j] == '?') {
            return dp[i][j] = solve(i-1, j-1, text, mask, dp);
        }

        if (mask[j] == '*') {
            int empty = solve(i, j-1, text, mask, dp);

            int multiple = solve(i-1, j, text, mask, dp);

            return dp[i][j] = empty || multiple;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string text, string mask) {

        int n = text.size();
        int m = mask.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, text, mask, dp);
    }
};
