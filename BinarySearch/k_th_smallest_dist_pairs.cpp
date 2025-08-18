https://leetcode.com/problems/find-k-th-smallest-pair-distance/

class Solution {
public:
    bool feasible(int dist, vector<int>& nums, int k) {
        int count = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            while (nums[j] - nums[i] > dist) {
                i++;
            }
            count += (j - i);
        }
        return count >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[nums.size() - 1] - nums[0];
        while (left < right) {
            int mid = (left + right) / 2;
            if (feasible(mid, nums, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
