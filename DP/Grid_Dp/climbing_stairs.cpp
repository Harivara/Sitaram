https://www.interviewbit.com/problems/stairs/

int fun(int i,vector<int>&dp){
    if(i==1 || i==0){
        return 1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int steps=fun(i-1,dp);
    if(i>=2){
        steps+=fun(i-2,dp);
    }
    return dp[i]=steps;
}
int Solution::climbStairs(int A) {
    vector<int>dp(A+1,0);
    // return fun(A,dp);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=A;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[A];
}
