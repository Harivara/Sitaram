
explanation: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/solutions/754682/wall-of-bricks-by-coder206-w0ok/?utm_source=chatgpt.com



class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        int n = target.size();

        int ans = target[0];

        for(int i = 1; i < n; i++) {

            if(target[i] > target[i-1]) {
                ans += target[i] - target[i-1];
            }
        }

        return ans;
    }
};
