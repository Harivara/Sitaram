// You have an array A of N integers A1 A2 .. An. 
// Find the longest increasing subsequence Ai1 Ai2 .. Ak (1 <= k <= N) that satisfies the following condition: 
// For every adjacent pair of numbers of the chosen subsequence Ai[x] and Ai[x+1] (1 < x < k), 
// the expression( Ai[x] & Ai[x+1] ) * 2 < ( Ai[x] | Ai[x+1] ) is true 
// Note: ‘&’ is the bitwise AND operation, ‘ | ‘ is the bit-wise OR operation 
// Input: The first line contains an integer, N, denoting the number of elements in A. 
// Each line i of the N subsequent lines (where 0 ≤ i < N) contains an integer describing Ai.

#include <bits/stdc++.h>
using namespace std;

// returns index of highest set bit (0-based)
int highestBit(int x) {
   int pos = -1;
    while (x > 0) {
        pos++;
        x >>= 1;   // divide by 2
    }
    return pos;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> dp(N, 1);
    int ans = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] &&
                ((A[j]&A[i])*2<(A[j]|A[i]))) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
    return 0;
}
