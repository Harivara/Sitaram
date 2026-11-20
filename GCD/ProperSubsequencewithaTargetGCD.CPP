// https://prachub.com/interview-questions/count-updates-that-admit-a-proper-subsequence-with-a-target-gcd

// Count Updates That Admit a Proper Subsequence with a Target GCD
// You are given an integer array nums of length n, a positive integer p, and an ordered list of updates queries.

// A good subsequence is a nonempty subsequence of the current array that:

// contains strictly fewer than n elements; and
// has greatest common divisor exactly equal to p .
// Each update [index, value] replaces nums[index] with value. Apply the updates in their given order, keeping each change for subsequent updates. After every update, decide whether at least one good subsequence exists.

// Return the number of updates whose resulting array has a good subsequence. Do not count the initial array before the first update.

// Function
// int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries)

// Example 1
// Input: nums = [6, 10, 15], p = 1, queries = [[0, 30], [1, 14], [2, 7]]

// Output: 2

// Explanation:

// After the first update, the array is [30, 10, 15] . All its elements are divisible by 5 , so there is no good subsequence for p = 1 .
// After the second update, [14, 15] is a good subsequence of [30, 14, 15] .
// After the third update, [30, 7] is a good subsequence of [30, 14, 7] .
// Exactly two resulting arrays qualify.







5. Overall algorithm
//////////////


// After every update:
// 1. Update nums[index].
// 2. Find elements divisible by p.
// 3. Divide eligible elements by p.
// 4. If eligible count is less than n:
//    - Calculate GCD of all eligible elements.
//    - If GCD is 1, increment the answer.
// 5. Otherwise:
//    - Calculate GCD excluding each element using prefix/suffix GCD.
//    - If any resulting GCD is 1, increment the answer.




4. How do we calculate GCD excluding an element?
We can use prefix and suffix GCD.

For an array:
a = [3, 5, 7, 10]


Construct:

Prefix GCD
prefix[0] = 3
prefix[1] = gcd(3, 5)
prefix[2] = gcd(3, 5, 7)
prefix[3] = gcd(3, 5, 7, 10)


Suffix GCD
suffix[3] = 10
suffix[2] = gcd(7, 10)
suffix[1] = gcd(5, 7, 10)
suffix[0] = gcd(3, 5, 7, 10)


If we exclude index i, the GCD of the remaining elements is:
\[
GCD_i=\gcd(prefix[i-1],suffix[i+1])
\]



#include <bits/stdc++.h>
using namespace std;

int countGoodSubseq(vector<int>& nums, int p,
                    vector<vector<int>>& queries) {

    int n = nums.size();
    int ans = 0;

    for (auto& q : queries) {

        // Apply update
        int index = q[0];
        int value = q[1];

        nums[index] = value;

        // Collect elements divisible by p
        vector<int> a;

        for (int x : nums) {
            if (x % p == 0) {
                a.push_back(x / p);
            }
        }

        int m = a.size();

        // No eligible elements
        if (m == 0) continue;

        // Case 1: We can select all eligible elements
        if (m < n) {

            int g = 0;

            for (int x : a) {
                g = gcd(g, x);
            }

            if (g == 1) {
                ans++;
            }
        }

        // Case 2: All n elements are eligible
        else {

            vector<int> prefix(n);
            vector<int> suffix(n);

            prefix[0] = a[0];

            for (int i = 1; i < n; i++) {
                prefix[i] = gcd(prefix[i - 1], a[i]);
            }

            suffix[n - 1] = a[n - 1];

            for (int i = n - 2; i >= 0; i--) {
                suffix[i] = gcd(suffix[i + 1], a[i]);
            }

            bool found = false;

            for (int i = 0; i < n; i++) {

                int g = 0;

                if (i > 0) {
                    g = gcd(g, prefix[i - 1]);
                }

                if (i < n - 1) {
                    g = gcd(g, suffix[i + 1]);
                }

                if (g == 1) {
                    found = true;
                    break;
                }
            }

            if (found) ans++;
        }
    }

    return ans;
}