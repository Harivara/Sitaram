https://leetcode.com/problems/valid-triangle-number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 0;
        
        // Fix the largest side nums[k]
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All elements from i to j-1 can form a triangle with nums[j] and nums[k]
                    count += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }
        
        return count;
    }
};
