we are given a string and we need to make the K parts of string , such that each part is a palindrome and we can swap character to make palindrome.

partition dp + minimum insertion to make palindrome Variation Question



#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "aabbcc";
    int K = 2;

    int n = s.size();

    // Precompute cost for every substring
    vector<vector<int>> cost(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {

        int freq[26] = {0};

        for (int j = i; j < n; j++) {

            freq[s[j] - 'a']++;

            int odd = 0;

            for (int x = 0; x < 26; x++) {
                if (freq[x] % 2 == 1)
                    odd++;
            }

            // Number of pairs that need correction
            cost[i][j] = odd / 2;
        }
    }

    // DP
    const int INF = 1e9;

    vector<vector<int>> dp(K + 1,
                           vector<int>(n + 1, INF));

    dp[0][0] = 0;

    for (int k = 1; k <= K; k++) {

        for (int i = 1; i <= n; i++) {

            for (int j = k - 1; j < i; j++) {

                dp[k][i] = min(
                    dp[k][i],
                    dp[k - 1][j] + cost[j][i - 1]
                );

            }
        }
    }

    cout << dp[K][n] << endl;

    return 0;
}



1st loop(k)
We calculate answers for:
- 1 partition
- 2 partitions
- 3 partitions
- ...
- K partitions

2nd loop(i)
This represents how many characters we have processed.

For example, if k = 2, then i starts from 2 because we cannot divide one character into two non-empty partitions.


3rd loop(j)
This tries every possible position where the last partition starts.



dp[k - 1][j] + cost[j][i - 1]
The idea is simple: We divide the string into two portions: the already-partitioned left portion and the new last partition on the right.