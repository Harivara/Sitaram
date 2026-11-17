2. Mountain Houses – Minimum Maximum Walking Distance to Dustbins

Input parameters: "N, matrix[N][2], K"

You are given N houses situated along a mountain road.

Each row of the matrix contains:

- First column: Position of the house (kilometres).

- Second column: Approval status (0 or 1).

A dustbin can only be installed at an approved house (approval = 1).

You have K dustbins that need to be installed. Every house must be served by a dustbin.

The objective is to minimize the maximum walking distance of any house to its nearest dustbin.

Example 1:

N = 3

matrix = [

[0, 1],

[5, 1],

[10, 1]

]

K = 3

Output = 0

Example 2:

N = 3

matrix = [

[0, 1],

[5, 1],

[10, 1]

]

K = 2

Output = 5

Example 3:

N = 3

matrix = [

[0, 1],

[5, 0],

[10, 1]

]

K = 1

Output = 10




#include <bits/stdc++.h>
using namespace std;

// Checks whether all houses can be covered
// using at most K dustbins with maximum distance D.

bool isPossible(vector<pair<int,int>>& houses, int K, int D) {

    int n = houses.size();
    int i = 0;
    int bins = 0;

    while (i < n) {

        // Leftmost uncovered house
        int x = houses[i].first;

        // Find the rightmost approved house
        // within the range [x-D, x+D].

        int pos = -1;

        for (int j = i; j < n && houses[j].first <= x + D; j++) {

            if (houses[j].first >= x - D &&
                houses[j].second == 1) {

                pos = j;
            }
        }

        // No approved house available to install dustbin
        if (pos == -1) {
            return false;
        }

        bins++;

        // More than K dustbins required
        if (bins > K) {
            return false;
        }

        // Install dustbin at the selected position
        int binPosition = houses[pos].first;

        // Skip all houses covered by this dustbin
        while (i < n && houses[i].first <= binPosition + D) {
            i++;
        }
    }

    return bins <= K;
}

int solve(int N, vector<pair<int,int>>& houses, int K) {

    // Sort houses by their positions
    sort(houses.begin(), houses.end());

    // Count approved houses only once
    int approved = 0;

    for (auto &h : houses) {
        if (h.second == 1) {
            approved++;
        }
    }

    // Cannot install exactly K dustbins
    if (approved < K) {
        return -1;
    }

    // Binary Search on Answer
    int low = 0;
    int high = houses.back().first - houses.front().first;

    int ans = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(houses, K, mid)) {

            ans = mid;
            high = mid - 1;

        }
        else {

            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> houses(N);

    for (int i = 0; i < N; i++) {
        cin >> houses[i].first >> houses[i].second;
    }

    cout << solve(N, houses, K) << endl;

    return 0;
}
