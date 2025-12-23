https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/?envType=daily-question&envId=2025-11-10


class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stack;
        int res = 0;
        for (int num : nums) {
            while (!stack.empty() && stack.back() > num)
                stack.pop_back();
            
            if (num == 0)
                continue;
            if (stack.empty() || stack.back() < num) {
                res++;
                stack.push_back(num);
            }
        }
        return res;
    }
};