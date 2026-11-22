https://leetcode.com/problems/partition-array-for-maximum-sum/?utm_source=chatgpt.com

class Solution {
public:

    int fun(int i,int n,vector<int>&arr,int k,vector<int>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi=0;
        int ans=0;
        for(int j=i;j<min(n,i+k);j++){
            maxi=max(arr[j],maxi);
            int len=j-i+1;
            ans=max(ans,len*maxi+fun(j+1,n,arr,k,dp));
        }
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return fun(0,n,arr,k,dp);
    }
};