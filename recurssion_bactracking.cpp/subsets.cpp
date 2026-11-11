// Subset problem is same as PICK and NOTPICK
// Instead of adding a recursive for not pick we can run a for loop.

#include <bits/stdc++.h>
using namespace std;

// void fun(int i, int n, vector<int>&curr, vector<vector<int>>&ans, vector<int>arr){
//     if(i==n){
//         ans.push_back(curr);
//         return;
//     }
//     curr.push_back(arr[i]);
//     fun(i+1,n,curr,ans,arr);
//     curr.pop_back();
//     fun(i+1,n,curr,ans,arr);
// }


    void fun(int start, vector<int>& nums,
             vector<int>& curr,
             vector<vector<int>>& ans) {

        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {

            // // Skip duplicates at the same recursion level
            // if(start>0 && nums[i]==nums[i-1]){
            //     continue;
            // }
            curr.push_back(nums[i]);
            fun(i + 1, nums, curr, ans);
            curr.pop_back(); // Backtrack
        }
    }

vector<vector<int> > subsets(vector<int>& A,int n) {
    //Write your code here
    vector<vector<int>>ans;
    vector<int>curr;
    fun(0,n,curr,ans,A);
    return ans;
}


///////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void fun(int i, vector<int>& nums,
             vector<int>& curr,
             vector<vector<int>>& ans) {

        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        } 
        // Pick nums[i]
        curr.push_back(nums[i]);
        fun(i + 1, nums, curr, ans);
        curr.pop_back();

        // Not pick nums[i]: skip all its duplicates
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }
        fun(j, nums, curr, ans);
    }

};