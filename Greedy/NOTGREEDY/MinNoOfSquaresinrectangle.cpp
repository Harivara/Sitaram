https://www.geeksforgeeks.org/problems/min-cut-square3303/1

class Solution {
public:
    int minCut(int a, int b) {

        vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));

        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= b; j++) {

                if(i == j) {
                    dp[i][j] = 1;
                    continue;
                }

                for(int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[k][j] + dp[i-k][j]);
                }

                for(int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[i][j-k]);
                }
            }
        }

        return dp[a][b];
    }
};