https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int fun(int ind,int buy,vector<int>A,int n,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=0;
    if(buy){
        profit=max(-A[ind]+fun(ind+1,0,A,n,dp),0+fun(ind+1,1,A,n,dp));
    }
    else{
        profit=max(A[ind]+fun(ind+1,1,A,n,dp),0+fun(ind+1,0,A,n,dp));
    }
    return dp[ind][buy]= profit;
}
int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    // return fun(0,1,A,n,dp);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            int profit=0;
            if(j==1){
               profit=max(-A[i]+dp[i+1][0],dp[i+1][1]); 
            }
            else{
               profit=max(A[i]+dp[i+1][1],dp[i+1][0]); 
                
            }
            dp[i][j]=profit;
        }
    }
    return dp[0][1];
  
}
