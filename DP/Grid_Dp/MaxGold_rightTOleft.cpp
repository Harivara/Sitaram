https://www.geeksforgeeks.org/dsa/gold-mine-problem/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxGold(int n, int m, vector<vector<int>> v) {

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Last column
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = v[i][m - 1];
        }

        // Move from right to left
        for (int j = m - 2; j >= 0; j--) {

            for (int i = 0; i < n; i++) {

                int right = dp[i][j + 1];

                int rightUp = 0;
                if (i > 0)
                    rightUp = dp[i - 1][j + 1];

                int rightDown = 0;
                if (i < n - 1)
                    rightDown = dp[i + 1][j + 1];

                dp[i][j] = v[i][j] +
                           max({right, rightUp, rightDown});
            }
        }

        // We can start from any row in column 0
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> M(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
        }
    }

    Solution ob;
    cout << ob.maxGold(n, m, M) << "\n";

    return 0;
}