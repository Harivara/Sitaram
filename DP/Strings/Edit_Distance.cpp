https://www.interviewbit.com/problems/edit-distance/

int fun(int i,int j,string A,string B,vector<vector<int>>&dp){
    if(i<0 && j>=0){
        return j+1;
    }
    if(j<0 && i>=0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(A[i]==B[j]){
        return dp[i][j]=fun(i-1,j-1,A,B,dp);
    }
    else{
        return dp[i][j]=1+min(fun(i-1,j,A,B,dp),min(fun(i-1,j-1,A,B,dp),fun(i,j-1,A,B,dp)));
    }
}

int Solution::minDistance(string A, string B) {
    int n =A.length();
    int m=B.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // return fun(n-1,m-1,A,B,dp);
    for(int i=0;i<=n;i++){
        dp[i][0 ]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    return dp[n][m];
}
