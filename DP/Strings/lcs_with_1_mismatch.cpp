/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, string s1, string s2, int flag){
    if(i==0 || j==0){
        return 0;
    }
    if(s1[i-1]==s2[j-1]){
            return 1+fun(i-1,j-1,s1,s2,flag);
    }
        
        else{
            if(flag==0){
                int used=1+fun(i-1,j-1,s1,s2,1);
                int notused=max(fun(i-1,j,s1,s2,0),fun(i,j-1,s1,s2,0));
            return max(used,notused);
            }
            
            else{
                return max(fun(i-1,j,s1,s2,flag),fun(i,j-1,s1,s2,flag));
            }
            
        }
    }

int lcs(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    int flag=0;
    
    // return fun(n,m,s1,s2,flag);
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,0)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k>=0;k--){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j][k]=1+dp[i-1][j-1][k];
                }
                else{
                    if(k==0){
                        int used=1+dp[i-1][j-1][1];
                        int notused=max(dp[i-1][j][0],dp[i][j-1][0]);
                        dp[i][j][k]=max(used,notused);
                    }
                    else{
                        dp[i][j][k]=max(dp[i-1][j][1],dp[i][j-1][1]);
                    }
                }
            }
        }
    }
    return dp[n][m][0];
}

int main()
{
    
    string s="abefa";
    string s1="baf";
    
    cout<<lcs(s1,s);    

    return 0;
}