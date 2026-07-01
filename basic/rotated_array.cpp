// https://leetcode.com/problems/next-greater-element-ii/

// class Solution {
//     public:
//         vector<int> nextGreaterElements(vector<int>& nums) {
//             int n = nums.size();
//             vector<int> res(n, -1);  // default to -1 (not found)
//             stack<int> st;  // store indices
    
//             for (int i = 2 * n - 1; i >= 0; i--) {
//                 int idx = i % n;
//                 while (!st.empty() && nums[st.top()] <= nums[idx]) {
//                     st.pop();
//                 }
//                 if (!st.empty()) {
//                     res[idx] = nums[st.top()];
//                 }
//                 st.push(idx);
//             }
    
//             return res;
//         }
//     };
    