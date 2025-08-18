https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                dp[i][j]=A[i][j];
            }
            else{
                if(A[i][j]!=0){
                    dp[i][j]=A[i][j]+dp[i-1][j];
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        sort(dp[i].rbegin(),dp[i].rend());
        for(int j=0;j<m;j++){
        res=max(res,(j+1)*dp[i][j]);
        }
    }
    return res;
}
