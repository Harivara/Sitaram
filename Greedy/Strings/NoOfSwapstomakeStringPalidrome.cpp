
#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s) {

    int n = s.size();
    int i = 0, j = n - 1;

    int swaps = 0;

    while (i < j) {

        if (s[i] == s[j]) {
            i++;
            j--;
            continue;
        }

        // Find a matching character for s[i]
        int k = j;

        while (k > i && s[k] != s[i]) {
            k--;
        }

        if (k == i) {

            // No matching character found.
            // Move the unmatched character to the middle.
            swap(s[i], s[i + 1]);
            swaps++;

        } else {

            // Arbitrary swap:
            // Directly swap matching character with s[j].
            swap(s[k], s[j]);

            swaps++;

            i++;
            j--;
        }
    }

    return swaps;
}

int main() {

    string s = "abb";

    cout << minSwaps(s) << endl;

    return 0;
}
