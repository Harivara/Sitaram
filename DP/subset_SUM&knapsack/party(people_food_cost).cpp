https://www.interviewbit.com/problems/tushars-birthday-party/
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n = A.size();
    int m = B.size();
    vector<pair<int, int>> p;
    int max_element = 0;

    for (int i = 0; i < m; i++) {
        p.push_back({B[i], C[i]});
    }

    for (int i = 0; i < n; i++) {
        max_element = max(max_element, A[i]);
    }

    sort(p.begin(), p.end());

    vector<vector<int>> dp(m, vector<int>(max_element + 1, 0));

    // Base case for first item
    for (int i = 0; i <= max_element; i++) {
        // if (i % p[0].first == 0) {
        //     dp[0][i] = (i / p[0].first) * p[0].second;
        // }
            dp[0][i] = i  * p[0].second; //p[0].first is always 1 given in question
    }

    // Build DP
    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= max_element; j++) {
            int nottake = dp[i - 1][j];
            int take = INT_MAX;
            if (p[i].first <= j) {
                take = p[i].second + dp[i][j - p[i].first];
            }
            dp[i][j] = min(nottake, take);
        }
    }

    // Answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[m - 1][A[i]];
    }

    return ans;
}
