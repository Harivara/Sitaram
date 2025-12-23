// https://leetcode.com/problems/contiguous-array/
// Equal No of 0 and 1

/*Given a binary array nums, return the maximum length
of a subarray with an equal number of 0 and 1*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=-1;     // on indexs so initialize with mp[0]=-1
        int one=0,zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero++;
            else one++;
            int diff=zero-one;
            if(mp.count(diff))
                ans=max(ans,i-mp[diff]);     //if same diff is found the array has equal 1 and 0s
            else
                mp[diff]=i;
        } 
        return ans;
    }
};


maximum length of subarray sum=k
//arguments of this code might differ
//from  leetcode version of this problem but
//the idea reamins same
int lenOfLongSubarr(int A[],  int N, int K)  { 
        int pre_sum = 0; //prefix sum
        int res = 0;
        unordered_map<int, int> mp; //{pref sum , index}
        mp[0] = -1; 
        for(int i = 0; i < N; i++) {
            pre_sum += A[i];
            if(mp.find(pre_sum - K) != mp.end()) // pre_sum - K found in hash
                res = max(res, i - mp[pre_sum - K]);
            if(mp.find(pre_sum) == mp.end()) // Check if prefix_sum exists in hash
                mp[pre_sum] = i;
        }
        return res;
    } 


// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

/*given an integer array nums and an integer x.
In one operation, you can either remove the leftmost
or the rightmost element from the array nums
and subtract its value from x
Return the minimum number of operations
to reduce x to exactly 0 if it is possible, otherwise, return -1.*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {//start 
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int rem = total - x;
        if (rem == 0)
            return nums.size();

        int length = maxSubArrayLen(rem, nums);

        if (length == 0)
            return -1;
        return n - length;
    }

    int maxSubArrayLen(int k, vector<int>& A) {//Code for Maximum size subarray given sum
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp; 
        mp[0] = -1;

        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (mp.find(sum - k) != mp.end())
                res = max(res, i - mp[sum - k]);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return res;
    }
};