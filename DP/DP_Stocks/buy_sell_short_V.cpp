https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

class Solution {
public:
    long long fun(int i,int n,int buy, vector<int>&prices,int k){
        if(i==n){
            return (buy==2)?0:INT_MIN;
        }
        if(k==0){
            return 0;
        }
        long long profit=0;
        if(buy==2){
            profit=max(max(-prices[i]+fun(i+1,n,0,prices,k), prices[i]+fun(i+1,n,1,prices,k)),fun(i+1,n,2,prices,k));
        }
        else if(buy==0){
            profit=max(prices[i]+fun(i+1,n,2,prices,k-1),fun(i+1,n,0,prices,k));
        }
        else{
            profit=max(-prices[i]+fun(i+1,n,2,prices,k-1),fun(i+1,n,1,prices,k));
        }
        return profit;
    }

    long long maximumProfit(vector<int>& prices, int K) {
        int n=prices.size();
        // return fun(0,n,-1,prices,k);
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(3,vector<long long>(K+1,-1e15)));

       
            for(int k=0;k<=K;k++){
                dp[n][2][k]=0;
            }

            for(int i=0;i<=n;i++){
                for(int j=0;j<=2;j++){

                dp[i][j][0]=0;
                }
            }
        

        for(int i=n-1;i>=0;i--){
            for(int j=2;j>=0;j--){
                for(int k=1;k<=K;k++){
                    

                    
                    long long profit=0;
                    if(j==2){
                        profit=max(max(-prices[i]+dp[i+1][0][k],prices[i]+dp[i+1][1][k]),dp[i+1][2][k]);
                    }
                    if(j==0){
                        profit=max(prices[i]+dp[i+1][2][k-1],dp[i+1][0][k]);
                    }
                    if(j==1){
                        profit=max(-prices[i]+dp[i+1][2][k-1],dp[i+1][1][k]);
                    }

                    dp[i][j][k]=profit;
                    

                }
            }
        }
        return dp[0][2][K];

    }
};