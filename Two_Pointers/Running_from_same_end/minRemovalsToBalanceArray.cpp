
// https://leetcode.com/problems/minimum-removals-to-balance-array/description/

// The value of j increases until nums[j]>nums[i]*k
// then the value of i increases untill nums[j]<=nums[i]*k
// if there is a vaild i and j value then removed numbers are 
// if i=3 then 3 numbers were removed index=0,1,2
// if j=4 and n=6 only 1 number is removed from right index=5
// so ans =(i+n-j-1)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n;  // Worst case: remove all elements
        int i = 0;
//  j=0 if there is only one number in the array and k=1 then it satisfies       
        for(int j = 0; j < n; ++j) {                          
            while (nums[j] > (long long)nums[i] * k) {
                i++;
            }
            ans = min(ans, i+n-j-1);
        }
        
        return ans;
    }
};