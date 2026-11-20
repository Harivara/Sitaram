class Solution {
public:

    int feasible(int mid,vector<int>&nums,int i){
        // if(i>=nums.size()){
        //     return 0;
        // }
        // int pick=0;
        // if(nums[i]<=mid){
        //     pick=1+feasible(mid,nums,i+2);
        // }
        // int notpick=feasible(mid,nums,i+1);
        // return max(pick,notpick);
                                                // vector<int>dp(nums.size()+2,0);
                                                // for(int i=nums.size()-1;i>=0;i--){
                                                //     int pick=0;
                                                //     if(nums[i]<=mid){
                                                //         pick=1+dp[i+2];
                                                //     }
                                                //     int notpick=dp[i+1];
                                                //     dp[i]=max(pick,notpick);
                                                // }
                                                // return dp[0];
                                                // }


    // GREEDY FEASIBLE SOLUTION
    int feasible(int mid, vector<int>& nums, int k) {

    int count = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] <= mid) {
            count++;
            i++;  // Skip adjacent house
        }

        if(count >= k) return true;
    }

    return false;
}

    int minCapability(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        for(int i:nums){
            left=min(left,i);
            right=max(right,i);
        }

        while(left<right){
            int mid=(right-left)/2+left;
            if(feasible(mid,nums,0)>=k){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};