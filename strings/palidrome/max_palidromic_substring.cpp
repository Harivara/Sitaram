https://leetcode.com/problems/longest-palindromic-substring/description/


// dp[i][j] =1 if s(i..j) is palidrome otherwise dp[i][j]=0; 
class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        int dp[n+1][n+1];
            int start=0,end=0;
    
for(int g=0;g<s.length();g++){    /// gap
    for(int i=0,j=g;j<s.length();j++,i++){
        if(g==0){
            dp[i][i]=1;      // gap=0 single char is always palidrome
        }
        else if(g==1){
            if(s[i]==s[j]){
                dp[i][j]=1;    // gap=1 size of 2 char is palidrome if 2 are equal
            }
            else{
                dp[i][j]=0;
            }
        }
        else{
             if(s[i]==s[j] && dp[i+1][j-1]==1){    // s(i,j) is palidrome for other gaps if inner gap is palidrome(i+1,j-1) and s[i]==s[j];
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