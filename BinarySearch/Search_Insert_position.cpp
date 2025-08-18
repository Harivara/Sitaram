https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;int right=nums.size();
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]>=target){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};

// we have to fing the minimal value of k where nums[k]>=target.  [1,3,5,6] target=5 then nums[2]>=5 (output=2)
//                                                                 [1,3,6,7] target=5 then nums[2]>=5 (outpu =2)
//                                                                 [1,3,6,7] target=9 then all elements are less we insert at nums[4];
//                         left=0 ,right=n(no.of.ELe)+1