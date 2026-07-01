// https://leetcode.com/problems/continuous-subarray-sum/solutions/5276981/prefix-sum-hashmap-patterns-7-problems-b-6794/

1. Count Subarrays with some given condtion

// https://leetcode.com/problems/subarray-sum-equals-k/submissions/1826287190/

/*Given an array of integers arr and an integer k,
return the total number of subarrays whose sum equals to k.*/


// (prefixsum at current Index)(j) - (prefixsum at previous)(i) =k  subarray_sum[i..j]=k
// mp[sum-k] stores the freq of previous indexes where sum of sub_array is k

// Adding the current prefix sum to the map for future subarrays
// If the current prefixsum-k is already present in the map then we can remove that subarray we can new subarray with sum k

// array = [2, 1, -2, 4 , -3] k=2
// subarray with sum k=2 are [2], [-2, 4], [2, 1, -2, 4, -3], [1, -2, 4, -3], [4, -3, 1] => total 5 subarrays

// for i=0 sum=2, count+=mp[2-2]=mp[0]=1, mp[2]=1  count=1
// for i=1 sum=3, count+=mp[3-2]=mp[1]=0, mp[3]=1  count=1
// for i=2 sum=1, count+=mp[1-2]=mp[-1]=0, mp[1]=1  count
// for i=3 sum=5, count+=mp[5-2]=mp[3]=1, mp[5]=1  count=2

// When i=3 subarray [2,1,-2,4] we can remove [2,1] and get new subarray [-2,4] with sum k=2
// How do we know that removed subarray sum is k? Because we have stored the prefix sum in the map and we can check if the current prefix sum - k is present in the map or not. If it is present then we can remove that subarray and get new subarray with sum k.
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