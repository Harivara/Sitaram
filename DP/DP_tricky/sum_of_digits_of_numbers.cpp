https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

int func(int digit,int sum,vector<vector<int>> &dp){
    if(sum==0 && digit>0){return 0;}
    if(digit==0){
        if(sum<=9 && sum>=1) return 1;
        else return 0;
    }
    if(dp[digit][sum]!=-1){
        return dp[digit][sum];
    }
    int ways=0;
    for(int i=0;i<=9;i++){
        if(i<=sum){
            ways += func(digit-1,sum-i,dp)%1000000007;
            ways = ways%1000000007;
        }
    }
    return dp[digit][sum]=ways%1000000007;
}
int Solution::solve(int A, int B) {
    vector<vector<int>> dp(A,vector<int>(B+1,-1));
    return func(A-1,B,dp);
}
