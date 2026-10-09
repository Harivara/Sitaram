class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int m = matrix.size();
        int n = matrix[0].size();

        // 2D prefix sum
        vector<vector<int>> pref(m + 1,
                                 vector<int>(n + 1, 0));

        for (int r = 1; r <= m; r++) {

            for (int c = 1; c <= n; c++) {

                pref[r][c] =
                    pref[r - 1][c]
                    + pref[r][c - 1]
                    - pref[r - 1][c - 1]
                    + matrix[r - 1][c - 1];
            }
        }

        int ans = INT_MIN;

        // Top row
        for (int r1 = 0; r1 < m; r1++) {

            // Bottom row
            for (int r2 = r1 + 1; r2 <= m; r2++) {

                // Left column
                for (int c1 = 0; c1 < n; c1++) {

                    // Right column
                    for (int c2 = c1 + 1; c2 <= n; c2++) {

                        int sum =
                            pref[r2][c2]
                            - pref[r1][c2]
                            - pref[r2][c1]
                            + pref[r1][c1];

                        if (sum <= k) {
                            ans = max(ans, sum);
                        }
                    }
                }
            }
        }

        return ans;
    }
};