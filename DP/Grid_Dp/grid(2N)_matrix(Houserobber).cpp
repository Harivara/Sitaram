https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int Solution::adjacent(vector<vector<int>> &A) {
    int n = A[0].size();
    if (n == 0) return 0;
    if (n == 1) return max(A[0][0], A[1][0]);

    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        B[i] = max(A[0][i], A[1][i]);
    }

    // Now do House Robber DP
    vector<int> dp(n, 0);
    dp[0] = B[0];
    dp[1] = max(B[0], B[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + B[i]);
    }

    return dp[n - 1];
}
