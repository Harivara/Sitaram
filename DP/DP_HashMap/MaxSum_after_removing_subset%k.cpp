// Intuition
// We want to minimize the sum left after deleting contiguous subarrays whose sums are divisible by k.
// The key observation is that if two prefix sums give the same remainder modulo k, 
// then the subarray between them has a sum divisible by k and can be deleted. 
// So at each index i, we have two choices: 
// either keep adding the current element to our leftover (carry forward from dp[i-1]), 
// or delete a valid divisible subarray and jump back to the leftover sum at an earlier index where the remainder was the same.

// Approach
// To implement this, we use dp[i] = minimum leftover sum for prefix [0..i-1]. 
// We also track a map mp from remainder → index, meaning the best point we can jump back to if we see this remainder again. 
// For each i, we calculate both options (keep vs. delete), take the minimum, 
// and update the map with the current index for the remainder. At the end, dp[n] gives the minimal leftover sum.



// https://leetcode.com/problems/minimum-sum-after-divisible-sum-deletions

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1, LLONG_MAX), mp(k, -1);
        dp[0] = 0;
        mp[0] = 0;
        long long prefixSum = 0;
        for(int i=1; i<=n; i++){
            prefixSum += nums[i-1];
            long long notPick = dp[i-1] + nums[i-1], pick = LLONG_MAX;
            int rem = prefixSum % k;
            if(rem < 0) rem += k;
            if(mp[rem] != -1){
                pick = dp[mp[rem]];
            }
            dp[i] = min<long long>(pick, notPick);
            mp[rem] = i;
        }
        return dp[n];
    }
};