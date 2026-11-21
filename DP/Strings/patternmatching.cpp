
class Solution {
public:

    bool solve(int i, int j, string &s, string &p) {

        // Pattern exhausted
        if (j < 0) {
            return i < 0;
        }

        // Text exhausted
        if (i < 0) {

            // Remaining pattern must be zero-occurrence pairs
            if (p[j] == '*') {
                return solve(i, j-2, s, p);
            }

            return false;
        }

        // Current pattern character is *
        if (p[j] == '*') {

            // Choice 1: Ignore preceding character and *
            bool zero = solve(i, j-2, s, p);

            // Choice 2: Match one or more occurrences
            bool multiple = false;

            if (p[j-1] == '.' || p[j-1] == s[i]) {
                multiple = solve(i-1, j, s, p);
            }

            return zero || multiple;
        }

        // Normal character or dot
        if (p[j] == '.' || p[j] == s[i]) {
            return solve(i-1, j-1, s, p);
        }

        return false;
    }

    bool isMatch(string s, string p) {

        return solve(s.size()-1, p.size()-1, s, p);
    }
};



class Solution {
public:

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(
            n+1, vector<bool>(m+1, false)
        );

        dp[0][0] = true;

        // Empty text
        for (int j = 2; j <= m; j++) {

            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (p[j-1] == '.' || p[j-1] == s[i-1]) {

                    dp[i][j] = dp[i-1][j-1];
                }

                else if (p[j-1] == '*') {

                    // Zero occurrences
                    dp[i][j] = dp[i][j-2];

                    // One or more occurrences
                    if (p[j-2] == '.' ||
                        p[j-2] == s[i-1]) {

                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};
