https://www.interviewbit.com/problems/distinct-subsequences/discussion/


// if a character matches we can consider it (dp[i-1][j-1]) or ignore it (dp[i-1][j])

int Solution::numDistinct(string A, string B) {

    int n=A.length();
    int m=B.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    
    for(int i=0;i<=n;i++)dp[i][0]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
    
}

