class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        int dp[n][n];
            int start=0,end=0;
    
for(int g=0;g<s.length();g++){
    for(int i=0,j=g;j<s.length();j++,i++){
        if(g==0){
            dp[i][i]=1;
        }
        else if(g==1){
            if(s[i]==s[j]){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
        else{
             if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
             }
             else{
                dp[i][j]=0;
             }
        }
        if(dp[i][j]==1){
             start=i;
             end=g+1;
        }
    }
}
        return s.substr(start,end);
        
    }
};