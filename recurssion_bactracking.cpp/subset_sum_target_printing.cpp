#include <bits/stdc++.h>
using namespace std;

void printSubsets(vector<int>& arr, int i, int sum,
                  vector<int>& curr,
                  vector<vector<int>>& res,
                  vector<vector<bool>>& dp) {
    if (sum == 0) {
        res.push_back(curr);
        return;
    }

    if (i == 0) return;

    // Without picking arr[i - 1]
    if (dp[i - 1][sum]) {
        printSubsets(arr, i - 1, sum, curr, res, dp);
    }

    // Picking arr[i - 1]
    if (sum >= arr[i - 1] &&
        dp[i - 1][sum - arr[i - 1]]) {

        curr.push_back(arr[i - 1]);

        printSubsets(arr, i - 1, sum - arr[i - 1],
                     curr, res, dp);

        curr.pop_back();
    }
}

vector<vector<int>> findSubsets(vector<int>& arr, int tar) {
    int n = arr.size();

    vector<vector<bool>> dp(
        n + 1, vector<bool>(tar + 1, false)
    );

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Tabulation
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= tar; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i][j] ||
                           dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    vector<vector<int>> res;

    if (!dp[n][tar]) return res;

    vector<int> curr;
    printSubsets(arr, n, tar, curr, res, dp);

    return res;
}

