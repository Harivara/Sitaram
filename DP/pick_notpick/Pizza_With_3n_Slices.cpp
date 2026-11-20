int solve(int i, int k, vector<int>& slices,
          vector<vector<int>>& dp, int start) {

    if (k == 0) return 0;

    if (i < start) return -1e9;

    if (dp[i][k] != -1)
        return dp[i][k];

    // Pick current element
    int pick = slices[i] +
        solve(i - 2, k - 1, slices, dp, start);

    // Don't pick current element
    int notPick =
        solve(i - 1, k, slices, dp, start);

    return dp[i][k] = max(pick, notPick);
}
int maxSizeSlices(vector<int>& slices) {

    int m = slices.size();
    int n = m / 3;

    vector<vector<int>> dp1(
        m, vector<int>(n + 1, -1)
    );

    vector<vector<int>> dp2(
        m, vector<int>(n + 1, -1)
    );

    // Case 1: Exclude last element
    int case1 = solve(m - 2, n, slices, dp1, 0);

    // Case 2: Exclude first element
    int case2 = solve(m - 1, n, slices, dp2, 1);

    return max(case1, case2);
}