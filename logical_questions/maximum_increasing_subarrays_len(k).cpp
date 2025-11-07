https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii

Take values of up and preUp for every index of i
If the two subarrays are discontinoues then the value of up is 1 and preUp is x
m is min(up,preUp)=1
candidate is max(half,m) i.e., (0,1)=1

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int up = 1, preUp = 0, res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) up++;
            else {
                preUp = up;
                up = 1;
            }
            int half = up/2; 
            int m = min(preUp, up);
            int candidate = max(half, m);
            if (candidate > res) res = candidate;
            cout<<i<<" up-"<<up<<" preUp-"<<preUp;
            cout<<" half-"<<half;
            cout<<" m-"<<m;
            cout<<" candidate-"<<candidate;
            cout<<" res-"<<res;
            cout<<endl;
        }
        return res;
    }
};