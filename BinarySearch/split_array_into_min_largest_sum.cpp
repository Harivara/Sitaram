https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
bool feasible(int sum,vector<int>&nums,int k){
    int total=0;
    int count=1;
    for(int i=0;i<nums.size();i++){
        total+=nums[i];
        if(total>sum){
            total=nums[i];
            count++;
            if(count>k){
                return false;
            }
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        for(int i=0;i<nums.size();i++){
            left=max(left,nums[i]);
            right=right+nums[i];
        }
        while(left<right){
            int mid=(left+right)/2;
            if(feasible(mid,nums,k)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }

};