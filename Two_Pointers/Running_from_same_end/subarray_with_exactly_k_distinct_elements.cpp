// 4. What if the question asks for exactly k distinct elements?
// This is an important interview variation.

// We can calculate:
// \[      
//                     Exactly(k) = AtMost(k) - AtMost(k-1)
// \]


// For at least K distinct integers, use the relationship:

//     {AtLeast(k) = TotalSubarrays - AtMost(k-1)}

class Solution {
public:

    int atMost(vector<int>& nums, int k) {

        if(k < 0) return 0;

        unordered_map<int,int> mp;

        int left = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++) {

            mp[nums[right]]++;

            while(mp.size() > k) {

                mp[nums[left]]--;

                if(mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atMost(nums, k) - atMost(nums, k-1);
    }
};
