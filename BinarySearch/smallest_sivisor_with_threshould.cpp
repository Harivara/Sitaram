https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:

    bool fun(int divisor,vector<int>&nums,int threshould){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%divisor==0){
                sum=sum+(nums[i]/divisor);
            }
            else{
                sum=sum+(nums[i]/divisor)+1;
            }
            if(sum>threshould){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=0;
        for(int i=0;i<nums.size();i++){
            right=max(right,nums[i]);
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(fun(mid,nums,threshold)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};