class Solution {
  public:
    // Function to compute the edit distance between two strings
    int n,m;
    int fun(int i,int j,string &s1,string s2){
        if(i==0){
            return j;
        }
        if(j==0){
            return i; 
        }
        if(s1[i]==s2[j]){
            return fun(i-1,j-1,s1,s2);
        }
        else{
            return 1+min(min(fun(i-1,j,s1,s2),fun(i,j-1,s1,s2)),fun(i-1,j-1,s1,s2));
        }
    }
    
    int editDistance(string& s1, string& s2) {
        // code here
        n=s1.length();
        m=s2.length();
        // return fun(n-1,m-1,s1,s2);
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                 dp[i][j]=dp[i-1][j-1];
             }
             else{
                 dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
             }
            }
        }
        
        return dp[n][m];
        
    }
};