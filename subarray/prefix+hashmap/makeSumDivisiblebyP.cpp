class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        int target = total % p;

        // Already divisible
        if (target == 0)
            return 0;

        unordered_map<int, int> mp;

        // remainder 0 occurs before the array
        mp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            int rem = prefix % p;

            int needed = (rem - target + p) % p;

            if (mp.find(needed) != mp.end()) {
                ans = min(ans, i - mp[needed]);
            }

            // Store the latest index
            mp[rem] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};