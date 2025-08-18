https://www.interviewbit.com/problems/0-1-knapsack/

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    vector<vector<int>>dp(n,vector<int>(C+1,0));
    for(int i=B[0];i<=C;i++){
        dp[0][i]=A[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=C;j++){
            int nottake=dp[i-1][j];
            int take=INT_MIN;
            if(B[i]<=j){
                take=dp[i-1][j-B[i]]+A[i];
            }
            dp[i][j]=max(take,nottake);
        }
    }
    return dp[n-1][C];
    }
    
    