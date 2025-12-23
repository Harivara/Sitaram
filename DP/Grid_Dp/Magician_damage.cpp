#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long helper(int ind, vector<long long>& v, vector<long long>& dp) {
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];

        // pick this index → skip next 2
        long long pick = v[ind] + helper(ind - 3, v, dp);
        // skip this index
        long long notpick = helper(ind - 1, v, dp);

        return dp[ind] = max(pick, notpick);
    }

    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: accumulate total damage for each power level
        map<int, long long> mp;
        for (int x : power)
            mp[x] += x;

        vector<pair<int, long long>> vals;
        for (auto &p : mp)
            vals.push_back(p);

        int n = vals.size();
        // vector<long long> dp(n,-1);
        // return helper(n-1, v, dp);
        vector<long long> dp(n, 0);
        dp[0] = vals[0].second;

        for (int i = 1; i < n; ++i) {
            // find the nearest previous index j where we can pick safely (gap >= 3)
            long long notpick = dp[i - 1];
            long long pick = vals[i].second;
            int j = i - 1;
            while (j >= 0 && vals[i].first - vals[j].first < 3) j--;
            if (j >= 0) pick += dp[j];

            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }
};
©leetcode