https://chatgpt.com/c/6afc1cc8-2678-83e8-9129-18f57394126d


#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {2, 3, 4, 8, 6, 12};

    int n = arr.size();
    int mx = 100000;

    // Step 1: Store the rightmost index of every value
    vector<int> rightmost(mx + 1, -1);

    for (int i = 0; i < n; i++) {
        rightmost[arr[i]] = i;
    }

    // Step 2: Store the rightmost index of a multiple
    vector<int> rightmostMultiple(mx + 1, -1);

    for (int d = 2; d <= mx; d++) {

        for (int multiple = d; multiple <= mx; multiple += d) {

            rightmostMultiple[d] = max(
                rightmostMultiple[d],
                rightmost[multiple]
            );
        }
    }

    // Step 3: Find maximum distance
    int maxDistance = -1;

    for (int i = 0; i < n; i++) {

        if (arr[i] > 1) {

            int j = rightmostMultiple[arr[i]];

            if (j > i) {
                maxDistance = max(maxDistance, j - i);
            }
        }
    }

    cout << maxDistance << endl;

    return 0;
}