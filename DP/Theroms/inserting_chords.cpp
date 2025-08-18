https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/



// 📌 Original Catalan Recurrence:
// Base Case:
// dp[0] = 1 → 0 chords, 0 points → 1 valid configuration (do nothing)

// Recurrence Relation:
// For dp[n], we try fixing one chord from point 1 to some even-numbered point 2k. This chord divides the circle into two independent smaller problems:

// One side with k-1 chords (i.e. 2*(k-1) points)

// Other side with n-k chords (i.e. 2*(n-k) points)

// So we iterate over all possible ways to divide n chords into i and n-1-i (because one chord is fixed, the remaining are n-1):


               

                                  // dp[3]=dp[0]⋅dp[2]+dp[1]⋅dp[1]+dp[2]⋅dp[0]

🔁 Symmetry Observation:

// dp[i]⋅dp[A−1−i]=dp[A−1−i]⋅dp[i]
// So each pair appears twice except the middle one when A is odd and i == A/2.
// But:

// If A is odd, and i == A/2, then i == A - 1 - i, so dp[i] * dp[i] is counted only once.

// We need to not double count that middle term when i == A - 1 - i.





int MOD = 1000000007;

int Solution::chordCnt(int A) {
    vector<long long> dp(A + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= A; i++) {
        for (int j = 0; j <= (i - 1) / 2; j++) {
            long long ways = (dp[j] * dp[i - 1 - j]) % MOD;
            if (j == i - 1 - j) {
                dp[i] = (dp[i] + ways) % MOD; // middle term only once
            } else {
                dp[i] = (dp[i] + 2 * ways) % MOD; // symmetric pair
            }
        }
    }

    return dp[A];
}
