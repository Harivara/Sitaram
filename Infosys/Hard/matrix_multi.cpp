// // class Solution {
// // public:
// //     int dp[101][101];

// //     int solve(int i, int j, vector<int>& arr) {
// //         if (i == j) return 0;

// //         if (dp[i][j] != -1)
// //             return dp[i][j];

// //         int ans = INT_MAX;

// //         for (int k = i; k < j; k++) {
// //             int cost = solve(i, k, arr)
// //                      + solve(k + 1, j, arr)
// //                      + arr[i - 1] * arr[k] * arr[j];
// //             ans = min(ans, cost);
// //         }

// //         return dp[i][j] = ans;
// //     }

// //     int matrixMultiplication(vector<int>& arr) {
// //         int n = arr.size();
// //         memset(dp, -1, sizeof(dp));
// //         return solve(1, n - 1, arr);
// //     }
// // };

// class Solution {
// public:
//     int matrixMultiplication(vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         // length = chain length
//         for (int len = 2; len < n; len++) {
//             for (int i = 1; i + len - 1 < n; i++) {
//                 int j = i + len - 1;
//                 dp[i][j] = INT_MAX;

//                 for (int k = i; k < j; k++) {
//                     int cost = dp[i][k]
//                              + dp[k + 1][j]
//                              + arr[i - 1] * arr[k] * arr[j];
//                     dp[i][j] = min(dp[i][j], cost);
//                 }
//             }
//         }
//         return dp[1][n - 1];
//     }
// };


class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, vector<int>& arr) {
        // Base case: one matrix, no multiplication needed
        if (i == j) return 0;

        // Memoized result
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        // Try all possible partitions
        for (int k = i; k < j; k++) {
            int cost = solve(i, k, arr)
                     + solve(k + 1, j, arr)
                     + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(1, n - 1, arr);
    }
};
