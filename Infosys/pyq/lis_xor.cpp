#include <bits/stdc++.h>
using namespace std;

int get_ans(int N, int M, vector<int>& A) {
    const int MAXX = 2048;  // safe upper bound for XOR
    vector<vector<int>> dp(N, vector<int>(MAXX, 0));

    int ans = 0;

    for (int i = 0; i < N; i++) {
        // Single element subsequence
        dp[i][A[i]] = 1;

        for (int j = 0; j < i; j++) {
            if (A[j] <= A[i]) {
                for (int x = 0; x < MAXX; x++) {
                    if (dp[j][x] > 0) {
                        int nx = x ^ A[i];
                        dp[i][nx] = max(dp[i][nx], dp[j][x] + 1);
                    }
                }
            }
        }

        // Check XOR condition
        for (int x = M; x < MAXX; x++) {
            ans = max(ans, dp[i][x]);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    cout << get_ans(N, M, A) << "\n";
    return 0;
}
