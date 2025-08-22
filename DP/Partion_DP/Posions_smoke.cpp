https://www.interviewbit.com/problems/potions/

int Solution::minSmoke(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> color(n, vector<int>(n, 0));

    // Precompute color[i][j] = sum of A[i..j] % 100
    for (int i = 0; i < n; i++) {
        color[i][i] = A[i];
        for (int j = i + 1; j < n; j++) {
            color[i][j] = (color[i][j - 1] + A[j]) % 100;
        }
    }

    // Fill dp table for lengths >= 2
    for (int diff = 1; diff < n; diff++) {
        int i=0;
            int j = i + diff;
            for(;j<n;i++,j++){
            dp[i][j] = INT_MAX;

            // Try all possible partitions: (i,k) + (k+1,j)
            for (int k = i; k < j; k++) {
                int leftSmoke = dp[i][k];
                int rightSmoke = dp[k + 1][j];
                int mixSmoke = color[i][k] * color[k + 1][j];
                int totalSmoke = leftSmoke + rightSmoke + mixSmoke;

                // Debug-style breakdown for understanding:
                // ------------------------------------------
                // Example: i = 0, j = 3
                // k = 0: (0,0) + (1,3)
                //        mix = color[0][0] * color[1][3]
                //        smoke = dp[0][0] + dp[1][3] + mix
                //
                // k = 1: (0,1) + (2,3)
                //        mix = color[0][1] * color[2][3]
                //        smoke = dp[0][1] + dp[2][3] + mix
                //
                // k = 2: (0,2) + (3,3)
                //        mix = color[0][2] * color[3][3]
                //        smoke = dp[0][2] + dp[3][3] + mix

                dp[i][j] = min(dp[i][j], totalSmoke);
            }
        }
    }

    return dp[0][n - 1];
}
