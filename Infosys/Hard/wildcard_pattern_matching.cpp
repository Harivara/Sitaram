class Solution {
  public:
    bool fun(int i, int j, string &txt, string &pat,
             vector<vector<int>> &dp) {

        // Base cases
        if (i == 0 && j == 0) return true;
        if (j == 0) return false;

        if (i == 0) {
            for (int k = 0; k < j; k++) {
                if (pat[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (pat[j - 1] == '?') {
            return dp[i][j] = fun(i - 1, j - 1, txt, pat, dp);
        }
        else if (pat[j - 1] == '*') {
            return dp[i][j] =
                fun(i, j - 1, txt, pat, dp) ||   // '*' = empty
                fun(i - 1, j, txt, pat, dp);     // '*' = consume char
        }
        else if (pat[j - 1] == txt[i - 1]) {
            return dp[i][j] = fun(i - 1, j - 1, txt, pat, dp);
        }
        else {
            return dp[i][j] = false;
        }
    }

    bool wildCard(string &txt, string &pat) {
        int n = txt.length();
        int m = pat.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return fun(n, m, txt, pat, dp);
    }
};
