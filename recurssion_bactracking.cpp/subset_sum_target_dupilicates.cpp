#include <bits/stdc++.h>
using namespace std;

void fun(int start, int target,
         vector<int>& candidates,
         vector<int>& curr,
         vector<vector<int>>& ans,
         vector<vector<bool>>& dp) {

    if (target == 0) {
        ans.push_back(curr);
        return;
    }

    int n = candidates.size();

    for (int j = start; j < n; j++) {

        // Skip duplicate values at the same recursion level
        if (j > start && candidates[j] == candidates[j - 1])
            continue;

        if (candidates[j] > target)
            break;

        // Check whether the remaining target is achievable
        if (!dp[j + 1][target - candidates[j]])
            continue;

        curr.push_back(candidates[j]);

        fun(j + 1, target - candidates[j],
            candidates, curr, ans, dp);

        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates,
                                    int target) {
    sort(candidates.begin(), candidates.end());

    int n = candidates.size();

    vector<vector<int>> ans;
    if (n == 0) return ans;

    // dp[i][sum]: Can sum be formed using candidates[i...n-1]?
    vector<vector<bool>> dp(
        n + 1, vector<bool>(target + 1, false)
    );

    // Sum zero is always achievable with the empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // No elements remain, so positive sums are impossible
    for (int i = n - 1; i >= 0; i--) {
        for (int sum = 1; sum <= target; sum++) {

            bool notPick = dp[i + 1][sum];
            bool pick = false;

            if (candidates[i] <= sum) {
                pick = dp[i + 1][sum - candidates[i]];
            }

            dp[i][sum] = pick || notPick;
        }
    }

    if (!dp[0][target]) return ans;

    vector<int> curr;
    fun(0, target, candidates, curr, ans, dp);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> res = combinationSum2(arr, target);

    for (const auto& combination : res) {
        for (int x : combination) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}