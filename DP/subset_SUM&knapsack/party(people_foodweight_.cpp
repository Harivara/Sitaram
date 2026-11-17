2)I was given a Nx4 matrix where n are number of dishes

The 1st column is weight of small container 2nd column is how many people it satisfies 3rd coloum is weight of big container and 4th is how many people it satisfies

I am also given a C that is the capacity we can hold

Atleast small or big container of all the N dishes has to be taken, if it's not possible the return -1

We have to maximize the number of people it satisfies




#include <bits/stdc++.h>
using namespace std;

int solve(int n, int C, vector<vector<int>>& arr) {

    const int NEG = -1e9;

    vector<vector<int>> dp(n + 1, vector<int>(C + 1, NEG));

    // Base case: No dishes remaining
    for (int c = 0; c <= C; c++) {
        dp[n][c] = 0;
    }

    for (int i = n - 1; i >= 0; i--) {

        for (int c = 0; c <= C; c++) {

            int small = NEG;
            if (c >= arr[i][0] && dp[i + 1][c - arr[i][0]] != NEG) {
                small = arr[i][1] + dp[i + 1][c - arr[i][0]];
            }

            int big = NEG;
            if (c >= arr[i][2] && dp[i + 1][c - arr[i][2]] != NEG) {
                big = arr[i][3] + dp[i + 1][c - arr[i][2]];
            }

            int small_big = NEG;
            if (c >= arr[i][0] + arr[i][2] &&
                dp[i + 1][c - arr[i][0] - arr[i][2]] != NEG) {

                small_big = arr[i][1] + arr[i][3] +
                            dp[i + 1][c - arr[i][0] - arr[i][2]];
            }

            dp[i][c] = max({small, big, small_big});
        }
    }

    return dp[0][C] == NEG ? -1 : dp[0][C];
}

int main() {

    int n = 3, C = 10;

    vector<vector<int>> arr = {
        {2, 3, 4, 6},
        {3, 4, 5, 8},
        {1, 2, 3, 5}
    };

    cout << solve(n, C, arr);

    return 0;
}