https://leetcode.com/problems/house-robber/
class Solution {
public:

 int fun(int i,vector<int>&nums){
    if(i>=nums.size()){
        return 0;
    }
    int pick=nums[i]+fun(i+2,nums);
    int notpick=fun(i+1,nums);
    return max(pick,notpick);
 }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,0);
      
        // return fun(0,nums)
        dp[n+1]=0;
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int pick=dp[i+2]+nums[i];
            int notpick=dp[i+1];
            dp[i]=max(pick,notpick);
            
        }
        return dp[0];
    }
};