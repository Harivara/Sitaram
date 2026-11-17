Q3. Painting Planks – Minimum Cost with Limited Paint Cans

Input parameters: "N, matrix[N][2], V"

You are given N planks that must be painted using either colour A or colour B.

Each row of the matrix contains:

- First column: Cost/quantity required to paint that plank with A.

- Second column: Cost of painting that plank with B.

You are also given V, representing the total available paint cans for colour A.

Conditions:

You cannot paint three consecutive planks with the same colour (AAA or BBB is not allowed).

The total number of cans consumed for painting with A must not exceed V.

Every plank must be painted.

Minimize the total painting cost.

If no valid arrangement is possible, return -1.



#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long minPaintingCost(int N, const vector<vector<int>>& matrix, int V) {
    if (N == 0) return 0;

    // 4 consecutive-colour states:
    // 0 -> ended with 'A'  (1 consecutive A)
    // 1 -> ended with 'AA' (2 consecutive A's)
    // 2 -> ended with 'B'  (1 consecutive B)
    // 3 -> ended with 'BB' (2 consecutive B's)
    // dp[state][usedA] = minimum total painting cost
    vector<vector<long long>> dp(4, vector<long long>(V + 1, INF));

    // Base case: Plank 0
    if (matrix[0][0] <= V) {
        dp[0][matrix[0][0]] = matrix[0][0]; // Paint plank 0 with A
    }
    dp[2][0] = matrix[0][1];                // Paint plank 0 with B

    // Transition for planks 1 to N - 1
    for (int i = 1; i < N; i++) {
        vector<vector<long long>> next_dp(4, vector<long long>(V + 1, INF));
        int costA = matrix[i][0];
        int costB = matrix[i][1];

        for (int usedA = 0; usedA <= V; usedA++) {
            // Option 1: Paint plank i with 'A' (only allowed if usedA + costA <= V)
            if (usedA + costA <= V) {
                // Coming from 'B' (state 2) or 'BB' (state 3) -> becomes 'A' (state 0)
                long long prevB = min(dp[2][usedA], dp[3][usedA]);
                if (prevB < INF) {
                    next_dp[0][usedA + costA] = min(next_dp[0][usedA + costA], prevB + costA);
                }

                // Coming from 'A' (state 0) -> becomes 'AA' (state 1)
                // (Coming from state 1 'AA' is skipped so 'AAA' never happens)
                if (dp[0][usedA] < INF) {
                    next_dp[1][usedA + costA] = min(next_dp[1][usedA + costA], dp[0][usedA] + costA);
                }
            }

            // Option 2: Paint plank i with 'B' (uses 0 cans of A)
            // Coming from 'A' (state 0) or 'AA' (state 1) -> becomes 'B' (state 2)
            long long prevA = min(dp[0][usedA], dp[1][usedA]);
            if (prevA < INF) {
                next_dp[2][usedA] = min(next_dp[2][usedA], prevA + costB);
            }

            // Coming from 'B' (state 2) -> becomes 'BB' (state 3)
            // (Coming from state 3 'BB' is skipped so 'BBB' never happens)
            if (dp[2][usedA] < INF) {
                next_dp[3][usedA] = min(next_dp[3][usedA], dp[2][usedA] + costB);
            }
        }

        dp = move(next_dp);
    }

    // Find the minimum cost across all valid ending states and usedA <= V
    long long ans = INF;
    for (int state = 0; state < 4; state++) {
        for (int usedA = 0; usedA <= V; usedA++) {
            ans = min(ans, dp[state][usedA]);
        }
    }

    return (ans >= INF) ? -1 : ans;
}

int main() {
    int N = 3;
    vector<vector<int>> matrix = {
        {2, 4},
        {3, 2},
        {5, 3}
    };
    int V = 9;

    cout << minPaintingCost(N, matrix, V) << endl; // Output: 7 (Arrangement: A, B, B)
    return 0;
}