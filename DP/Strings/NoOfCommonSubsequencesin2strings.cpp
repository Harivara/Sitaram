// // https://www.geeksforgeeks.org/dsa/count-common-subsequence-in-two-strings/

// ```cpp
// #include <iostream>
// #include <string>
// using namespace std;

// class Result {
// public:
//     static int solve(const string& s1, const string& s2, int i, int j) {
//         // If either string is empty
//         // Only the empty subsequence is common
//         if (i == 0 || j == 0)
//             return 1;

//         // If characters are equal
//         if (s1[i - 1] == s2[j - 1]) {
//             return solve(s1, s2, i - 1, j)
//                  + solve(s1, s2, i, j - 1);

// ////////using the above fact all the previous 
// ////////common sub-sequences are doubled as they get 
/////////// appended by one more character

//         }

//         // If characters are different
//         return solve(s1, s2, i - 1, j)
//              + solve(s1, s2, i, j - 1)
//              - solve(s1, s2, i - 1, j - 1);
//     }

//     static int countCommonSubsequences(const string& s1, const string& s2) {
//         // Subtract 1 to exclude the empty subsequence
//         return solve(s1, s2, s1.length(), s2.length()) - 1;
//     }
// };

// int main() {
//     string s1, s2;
//     getline(cin, s1);
//     getline(cin, s2);

//     int result = Result::countCommonSubsequences(s1, s2);
//     cout << result << endl;

//     return 0;
// }
// ```


// C++ program to count common subsequence in two strings
#include <bits/stdc++.h>
using namespace std;

// return the number of common subsequence in
// two strings
int CommonSubsequencesCount(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();
    int dp[n1+1][n2+1];

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            dp[i][j] = 0;
        }
    }

    // for each character of S
    for (int i = 1; i <= n1; i++) {

        // for each character in T
        for (int j = 1; j <= n2; j++) {

            // if character are same in both 
            // the string
            if (s[i - 1] == t[j - 1]) 
                dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];            
            else 
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - 
                                        dp[i - 1][j - 1];            
        }
    }

    return dp[n1][n2];
}

// Driver Program
int main()
{
    string s = "ajblqcpdz";
    string t = "aefcnbtdi";

    cout << CommonSubsequencesCount(s, t) << endl;
    return 0;
}