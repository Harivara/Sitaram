https://www.interviewbit.com/problems/chain-of-pairs/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
        int res=0;

    vector<int>dp(n+1,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(A[i][0]>A[j][1]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
                    res=max(dp[i],res);

        }
    }
    
  
    return res;
}
