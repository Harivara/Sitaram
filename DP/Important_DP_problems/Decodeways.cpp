// https://www.interviewbit.com/problems/ways-to-decode/

#include<bits/stdc++.h>
using namespace std;
int fun(int i,string A,int n,vector<int>&dp){
    if(i==n){
        return 1;
    }
    if(A[i]=='0'){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int count=fun(i+1,A,n,dp);
    if(i+1<n){
        int val=stoi(A.substr(i,2));
        if(val<=26)
        count+=fun(i+2,A,n,dp);
    }
    return dp[i]= count;
}
int numDecodings(string A) {
    int MOD=1000000007;
    int n=A.size();
    vector<int>dp(n+1,0);
    // return fun(0,A,n,dp);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        if(A[i]=='0'){
            dp[i]=0;
            continue;
        }
        int count=dp[i+1];
        if(i+1<n){
        int val=stoi(A.substr(i,2));
        if(val<=26)
        count+=dp[i+2];
    }
    dp[i]=count%MOD;
    }
    return dp[0];
}

int main(){
    string A="2036";
    int k=numDecodings(A);
    cout<<k;
    return 0;

}