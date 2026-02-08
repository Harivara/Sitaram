// https://leetcode.com/problems/continuous-subarray-sum/solutions/5276981/prefix-sum-hashmap-patterns-7-problems-b-6794/

1. Count Subarrays with some given condtion

// https://leetcode.com/problems/subarray-sum-equals-k/submissions/1826287190/

/*Given an array of integers arr and an integer k,
return the total number of subarrays whose sum equals to k.*/


// (prefixsum at current Index)(j) - (prefixsum at previous)(i) =k  subarray_sum[i..j]=k
// mp[sum-k] stores the freq of previous indexes where sum of sub_array is k
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : arr) {
            sum += it;
            count += mp[sum - k];
            mp[sum]++; 
        }
        return count;
    }
};

// Subarray divisible by k
// https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i : nums) {
            sum = (sum + i) % k;
            if (sum < 0)
                sum = sum + k; // ADD k if sum negative to make it positive
            count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};