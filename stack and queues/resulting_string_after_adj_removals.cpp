https://leetcode.com/problems/resulting-string-after-adjacent-removals/

// class Solution {
// public:
//     string resultingString(string s) {
//         int n=s.length();
//         int i=0;
//         while(i<s.length()){
//             if(s[i]+1==s[i+1] || s[i]-1==s[i+1]){
//                 s.erase(i,2);
//                 if(i!=0){
//                     i=i-1;
//                     continue;
//                 }
//                 else{
//                     continue;
//                 }
//             }
//             if((s[i]=='a' && s[i+1]=='z') || (s[i]=='z' && s[i+1]=='a')){
//                  s.erase(i,2);
//                 if(i!=0){
//                     i=i-1;
//                     continue;
//                 }
//                 else{
//                     continue;
//                 }
//             }
//             i++;
//         }
//         return s;
//     }
// };

class Solution {
public:
    bool is_consecutive(char a, char b) {
        return abs(a - b) == 1 || (a == 'a' && b == 'z') || (a == 'z' && b == 'a');
    }

    string resultingString(string s) {
        string stack;

        for (char ch : s) {
            if (!stack.empty() && is_consecutive(stack.back(), ch)) {
                stack.pop_back();  // Remove the pair
            } else {
                stack.push_back(ch);
            }
        }

        return stack;
    }
};


        // RETURN LEXOGRAPHICALLY SMALLEST STRING
https://leetcode.com/problems/lexicographically-smallest-string-after-adjacent-removals/solutions/6778382/bruteforce-to-optimal-dp-c/

class Solution {
public:
    bool isConsec(char a, char b) {
        return abs(a - b) == 1 || abs(a - b) == 25;
    }

    string lexicographicallySmallestString(string s) {
        int n = s.size();
        vector<vector<string>> dp(n + 1, vector<string>(n + 1, ""));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len;

                // Base: Keep s[i]
                string res = s[i] + dp[i + 1][j];

                // Try to remove s[i] and s[k] if possible
                for (int k = i + 1; k < j; k++) {
                    if (isConsec(s[i], s[k]) && dp[i + 1][k] == "") {
                        res = min(res, dp[k + 1][j]);
                    }
                }

                dp[i][j] = res;
            }
        }

        return dp[0][n];
    }
};