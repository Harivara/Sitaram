int Solution::solve(const vector<int> &A) {
    int n=A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    map<int, int> mp;
    int ans=0;
    if(n<=2)
    {
        return n;
    }
   
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(mp.find(2*A[i] -A[j]) != mp.end())
            {
                dp[i][j] = max(dp[i][j] , 1+dp[mp[2*A[i] -A[j]]][i]);
            }
            else
            {
                dp[i][j]=2;
            }
            ans=max(ans, dp[i][j]);
        }
        mp[A[i]]=i;
    }
    return ans;
}


// a    a+d     a+2d
// 2(a+d)-(a+2d)=a ----> same concept is used
