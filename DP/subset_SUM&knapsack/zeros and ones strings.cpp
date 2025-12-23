https://leetcode.com/problems/ones-and-zeroes/?envType=daily-question&envId=2025-11-11

class Solution {
public:
int fun(vector<pair<int,int>>&value,int ind,int m,int n,vector<vector<vector<int>>>&dp){
    if(ind==0){
        if(value[ind].first<=m && value[ind].second<=n){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(m<0 && n<0){
        return 0;
    }
    if(dp[ind][m][n]!=-1){
        return dp[ind][m][n];
    }
    int notpick=fun(value,ind-1,m,n,dp);
    int pick=-1e9;
    if(value[ind].first<=m && value[ind].second<=n){
        pick=1+fun(value,ind-1,m-value[ind].first,n-value[ind].second,dp);
    }
    return dp[ind][m][n]=max(pick,notpick);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>value;
        for(int i=0;i<strs.size();i++){
            int count=0;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0'){
                    count++;
                }
            }
            value.push_back({count,strs[i].length()-count});
        }
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,0)));
// return fun(value,strs.size()-1,m,n,dp);
    for(int i=0;i<strs.size();i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=n;k++){
                if(i==0){
                       if(value[i].first<=j && value[i].second<=k){
                            dp[i][j][k]= 1;
                        }
                        else{
                            dp[i][j][k]= 0;
                        }
                }
                else{
                    int notpick=dp[i-1][j][k];
                    int pick=-1e9;
                    if(value[i].first<=j && value[i].second<=k){
                        pick=1+dp[i-1][j-value[i].first][k-value[i].second];
                    }
                
                    dp[i][j][k]=max(pick,notpick);
                }
               
            }
        }
    }
    return dp[strs.size()-1][m][n];
    }
};