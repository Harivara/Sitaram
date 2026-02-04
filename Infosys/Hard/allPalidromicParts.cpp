// class Solution {
// public:
//     vector<vector<string>> res;
//     vector<string> path;

//     bool isPalindrome(string &s, int l, int r) {
//         while (l < r) {
//             if (s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }

//     void backtrack(int idx, string &s) {
//         if (idx == s.size()) {
//             res.push_back(path);
//             return;
//         }

//         for (int i = idx; i < s.size(); i++) {
//             if (isPalindrome(s, idx, i)) {
//                 path.push_back(s.substr(idx, i - idx + 1));
//                 backtrack(i + 1, s);
//                 path.pop_back();  // backtrack
//             }
//         }
//     }

//     vector<vector<string>> palinParts(string &s) {
//         backtrack(0, s);
//         return res;
//     }
// };


class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> pal;

    void dfs(int idx, string &s) {
        if (idx == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (pal[idx][i]) {
                path.push_back(s.substr(idx, i - idx + 1));
                dfs(i + 1, s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> palinParts(string &s) {
        int n = s.size();
        pal.assign(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        dfs(0, s);
        return res;
    }
};
