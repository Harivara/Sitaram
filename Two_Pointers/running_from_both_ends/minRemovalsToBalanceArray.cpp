
https://leetcode.com/problems/minimum-removals-to-balance-array/description/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n;  // Worst case: remove all elements
        int i = 0;
        
        for(int j = 0; j < n; ++j) {
            while (nums[j] > (long long)nums[i] * k) {
                i++;
            }
            ans = min(ans, n - (j - i + 1));
        }
        
        return ans;
    }
};