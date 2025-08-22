https://www.interviewbit.com/problems/paint-house/

int Solution::solve(vector<vector<int>> &A) {
    int n = A.size();
    if (n == 0) return 0;

    // Create DP table where dp[i][j] = min cost to paint house 0..i with color j at i
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Base case: cost for painting first house with each color
    for (int j = 0; j < 3; j++) {
        dp[0][j] = A[0][j];
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        dp[i][0] = A[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = A[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = A[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    // The answer is the minimum of the three options for the last house
    return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int fun(int ind, int prevColor, vector<vector<int>>& A, vector<vector<int>>& dp) {
    int n = A.size();
    int m = A[0].size(); // should be 3

    if (ind == n) return 0;  // all houses painted

    if (dp[ind][prevColor] != -1) 
        return dp[ind][prevColor];

    int cost = INT_MAX;
    for (int color = 0; color < m; color++) {
        if (color != prevColor) {
            cost = min(cost, A[ind][color] + fun(ind + 1, color, A, dp));
        }
    }

    return dp[ind][prevColor] = cost;
}

int Solution::solve(vector<vector<int>> &A) {
    int n = A.size();
    int m = A[0].size(); // should be 3
    int minCost = INT_MAX;

    // dp[n][4] (prevColor = 0,1,2,3) where 3 means "no previous color"
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));

    // Start with prevColor = m (i.e., no restriction for first house)
    for (int color = 0; color < m; color++) {
        minCost = min(minCost, A[0][color] + fun(1, color, A, dp));
    }

    return minCost;
}
