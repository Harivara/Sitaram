https://leetcode.com/problems/largest-number/description/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa;
        });
        string ans = "";
        if (nums[0] == 0) {
            return "0";
        }
        for (int i = 0; i < nums.size(); i++) {
            ans = ans + to_string(nums[i]);
        }
        return ans;
    }
};