https://www.interviewbit.com/problems/0-1-knapsack/


// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  public:
  int fun(int ind,int W,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
      if(ind==0){
          if(wt[0]<=W){
              return val[0];
          }
          else{
              return 0;
          }
      }
      
      if(dp[ind][W]!=-1){
          return dp[ind][W];
      }
      
      int notpick=fun(ind-1,W,val,wt,dp);
      int pick=0;
      if(wt[ind]<=W){
          pick=val[ind]+fun(ind-1,W-wt[ind],val,wt,dp);
      }
      
      return max(pick,notpick);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        // vector<vector<int>>dp(n,vector<int>(W+1,0));
        // // return fun(n-1,W,val,wt,dp);
        
        // for(int w=wt[0];w<=W;w++){
        //     dp[0][w]=val[0];
        // }
        
        // for(int i=1;i<n;i++){
        //     for(int w=0;w<=W;w++){
        //         int notpick=dp[i-1][w];
        //         int pick=0;
        //         if(wt[i]<=w){
        //             pick=val[i]+dp[i-1][w-wt[i]];
        //         }
        //         dp[i][w]=max(pick,notpick);
        //     }
        // }
        // return dp[n-1][W];
        
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        
        for(int w=wt[0];w<=W;w++){
            prev[w]=val[0];
        }
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                int notpick=prev[w];
                int pick=0;
                if(wt[i]<=w){
                    pick=val[i]+prev[w-wt[i]];
                }
                curr[w]=max(pick,notpick);
            }
            prev=curr;
        }
        return prev[W];
    }
};
// int Solution::solve(vector<int> &A, vector<int> &B, int C) {
//     int n=A.size();
//     vector<vector<int>>dp(n,vector<int>(C+1,0));
//     for(int i=B[0];i<=C;i++){
//         dp[0][i]=A[0];
//     }
//     for(int i=1;i<n;i++){
//         for(int j=0;j<=C;j++){
//             int nottake=dp[i-1][j];
//             int take=INT_MIN;
//             if(B[i]<=j){
//                 take=dp[i-1][j-B[i]]+A[i];
//             }
//             dp[i][j]=max(take,nottake);
//         }
//     }
//     return dp[n-1][C];
//     }
    
    