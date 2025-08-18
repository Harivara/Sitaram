https://www.interviewbit.com/problems/longest-common-subsequence/

// int fun(int i,int j,string A,string B,vector<vector<int>>&dp){
//     if(i<0||j<0){
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(A[i]==B[j]){
//         return dp[i][j]= 1+fun(i-1,j-1,A,B,dp);
//     }
//     else{
//         return dp[i][j]=max(fun(i-1,j,A,B,dp), fun(i,j-1,A,B,dp));
//     }
// }
int Solution::solve(string A, string B) {
    int n=A.length(),m=B.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // return fun(n-1,m-1,A,B,dp);
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
    
}
