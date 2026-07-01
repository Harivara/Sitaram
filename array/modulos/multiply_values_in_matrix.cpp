https://leetcode.com/problems/construct-product-matrix/description/?envType=daily-question&envId=2026-03-24

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        long long pref = 1;

        // Prefix pass
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = pref;
                pref = (pref * (grid[i][j] % MOD)) % MOD;
            }
        }

        long long suf = 1;

        // Suffix pass
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                ans[i][j] = (1LL * ans[i][j] * suf) % MOD;
                suf = (suf * (grid[i][j] % MOD)) % MOD;
            }
        }

        return ans;
    }
};