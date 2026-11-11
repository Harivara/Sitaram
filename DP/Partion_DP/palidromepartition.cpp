class Solution {
public:

bool ispalidrome(int low,int high, string s){
    while(low<high){
        if(s[low]!=s[high]){
            return false;
        }
        low++;high--;
    }
    return true;
}
    int minCut(string s) {
        int n=s.length();
      vector<vector<int>>dp(n,vector<int>(n,0));
      for(int len=1;len<n;len++){
        for(int i=0;i+len<n;i++){
            int j=i+len;
            dp[i][j]=INT_MAX;
            if(ispalidrome(i,j,s)){
                dp[i][j]=0;
                continue;
            }
            else{
                for(int k=i;k<j;k++){
                    int cuts=1+dp[i][k]+dp[k+1][j];
                    dp[i][j]=min(dp[i][j],cuts);
            }
            }
            
        }
      } 
      return dp[0][n-1]; 
    }
};