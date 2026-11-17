// Maintain two DP arrays:
// - up[i]: Longest alternating subsequence ending at i with an increasing last element.
// - down[i]: Longest alternating subsequence ending at i with a decreasing last element.

// https://leetcode.com/problems/wiggle-subsequence/?utm_source=chatgpt.com

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        vector<int> up(n, 1);
        vector<int> down(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] + 1);
                }
                else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, max(up[i], down[i]));
        }

        return ans;
    }
};



class Solution {
public:

    int fun(int i, int prev, int flag, vector<int>& nums) {

        if(i == nums.size()) {
            return 0;
        }

        // Not pick
        int notpick = fun(i + 1, prev, flag, nums);

        int pick = 0;

        if(prev == -1) {
            // First element can always be picked
            pick = 1 + fun(i + 1, i, flag, nums);
        }
        else {
            if(flag == 0 && nums[i] > nums[prev]) {
                pick = 1 + fun(i + 1, i, 1, nums);
            }
            else if(flag == 1 && nums[i] < nums[prev]) {
                pick = 1 + fun(i + 1, i, 0, nums);
            }
        }

        return max(pick, notpick);
    }

    int wiggleMaxLength(vector<int>& nums) {

        return fun(0, -1, 0, nums);
    }
};



class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(n + 1, vector<int>(2, 0))
        );

        for(int i = n - 1; i >= 0; i--) {

            for(int prev = i - 1; prev >= -1; prev--) {

                for(int flag = 0; flag < 2; flag++) {

                    // Not pick
                    int notpick = dp[i + 1][prev + 1][flag];

                    int pick = 0;

                    if(prev == -1) {
                        pick = 1 + dp[i + 1][i + 1][flag];
                    }
                    else {

                        if(flag == 0 && nums[i] > nums[prev]) {
                            pick = 1 + dp[i + 1][i + 1][1];
                        }
                        else if(flag == 1 && nums[i] < nums[prev]) {
                            pick = 1 + dp[i + 1][i + 1][0];
                        }
                    }

                    dp[i][prev + 1][flag] = max(pick, notpick);
                }
            }
        }

        return max(dp[0][0][0], dp[0][0][1]);
    }
};



class Solution {
public:
    vector<int> wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return {};

        vector<vector<int>> up(n), down(n);

        for (int i = 0; i < n; i++) {
            up[i] = {nums[i]};
            down[i] = {nums[i]};
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j]) {
                    if (down[j].size() + 1 > up[i].size()) {
                        up[i] = down[j];
                        up[i].push_back(nums[i]);
                    }
                }

                else if (nums[i] < nums[j]) {
                    if (up[j].size() + 1 > down[i].size()) {
                        down[i] = up[j];
                        down[i].push_back(nums[i]);
                    }
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (up[i].size() > ans.size())
                ans = up[i];

            if (down[i].size() > ans.size())
                ans = down[i];
        }

        return ans;
    }
};