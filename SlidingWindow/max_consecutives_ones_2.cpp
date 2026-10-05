// you can flip one zero 


// find the max sub array with one zero; 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int zeros = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0)
                zeros++;

            while (zeros > 1) {
                if (nums[left] == 0)
                    zeros--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};