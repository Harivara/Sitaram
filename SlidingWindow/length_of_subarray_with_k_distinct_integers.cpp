class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int left = 0;
        int ans = 0;

        unordered_map<int, int> mp;

        for (int right = 0; right < n; right++) {

            mp[nums[right]]++;

            // More than k distinct elements
            while (mp.size() > k) {

                mp[nums[left]]--;

                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            // Exactly k distinct elements
            if (mp.size() == k) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};