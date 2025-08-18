https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    int fun(int ind, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (ind == 0) {
            return (nums[0] == target);
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        int notpick = fun(ind - 1, nums, target, dp);
        int pick = false;
        if (target >= nums[ind]) {
            pick = fun(ind - 1, nums, target - nums[ind], dp);
        }
        return dp[ind][target] = (pick || notpick);
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto i : nums) {
            total += i;
        }
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1,false));
        // return fun(nums.size() - 1, nums, target, dp);
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        // dp[0][target]=true;
        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool notpick=dp[i-1][k];
                bool pick=false;
                if(k>=nums[i]){
                    pick=dp[i-1][k-nums[i]];
                }
                dp[i][k]=(pick || notpick);
            }
        }
        return dp[n-1][target];
    }
};