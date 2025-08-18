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


int fun(int i,int prevcolor,vector<vector<int>>&A,vector<vector<int>>&dp){
    if(i<0){
        return 0;
    }
    if(dp[i][prevcolor+1]!=-1){
        return dp[i][prevcolor+1];
    }
    int mincost=INT_MAX;
    for(int color=0;color<3;color++){
        if(color!=prevcolor){
            int cost=A[i][color]+fun(i-1,color,A,dp);
            mincost=min(cost,mincost);
        }
    }
    return  dp[i][prevcolor+1]=mincost;
}
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>>dp(n+1,vector<int>(4,0));
    // return fun(n-1,-1,A,dp);
    for(int i=1;i<=n;i++){
        int mincost=INT_MAX;
    for(int color=0;color<3;color++){
        if(color!=prevcolor){
            int cost=A[i][color]+fun(i-1,color,A,dp);
            mincost=min(cost,mincost);
        }
    }
    return  dp[i][prevcolor+1]=mincost;
    }
}
