class Solution {
public:
    int solve(int i, int j, vector<int>& nums,
              vector<vector<int>>& dp,
              vector<int>& prefix) {

        // Only one stone remains
        if (i == j) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // Try every possible split
        for (int k = i; k < j; k++) {

            int leftSum = prefix[k + 1] - prefix[i];

            int rightSum = prefix[j + 1] - prefix[k + 1];

            if (leftSum < rightSum) {

                // Retain left subarray
                ans = max(ans,
                    leftSum + solve(i, k, nums, dp, prefix));

            }
            else if (leftSum > rightSum) {

                // Retain right subarray
                ans = max(ans,
                    rightSum + solve(k + 1, j, nums, dp, prefix));

            }
            else {

                // Both sums are equal: choose either
                int left = solve(i, k, nums, dp, prefix);
                int right = solve(k + 1, j, nums, dp, prefix);

                ans = max(ans, leftSum + max(left, right));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(
            n, vector<int>(n, -1)
        );

        return solve(0, n - 1, stoneValue, dp, prefix);
    }
};





class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len represents current interval length
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                int ans = 0;

                // Try every possible partition
                for (int k = i; k < j; k++) {

                    int leftSum = prefix[k + 1] - prefix[i];

                    int rightSum = prefix[j + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {

                        ans = max(ans,
                            leftSum + dp[i][k]);

                    }
                    else if (leftSum > rightSum) {

                        ans = max(ans,
                            rightSum + dp[k + 1][j]);

                    }
                    else {

                        ans = max(ans,
                            leftSum + max(dp[i][k], dp[k + 1][j]));

                    }
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }
};
