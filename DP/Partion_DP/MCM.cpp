class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = number of matrices in chain
        for (int diff = 2; diff < n; diff++) {
            for (int i = 1,j=diff+i-1; j < n; i++,j++) {

                
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j],
                            dp[i][k] + dp[k+1][j]
                            + arr[i-1] * arr[k] * arr[j]);
                    
                }
            }
        }

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
}
        return dp[1][n-1];
    }
};
