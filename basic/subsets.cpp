#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateSubsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> subsets;

    // Loop over all possible bitmasks (0 .. 2^n - 1)
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) { // if j-th bit is set
                subset.push_back(nums[j]);
            }
        }
        subsets.push_back(subset);
    }

    mask=0 {}
    mask=1 ,j=0 {1}
    mask=2, j=1 {2}
    mask=3, j=0 {1} j=1 {2} --> {1,2}
    mask=4, j=2 {3}
    mask=5, j=0 {1} j=2 {3} --> {1,3}
    mask=6, j=1 {2} j=2 {3} --> {2,3}
    mask=7   j=0,j=1,j=2 --> {1,2,3}
    return subsets;
}

#include <bits/stdc++.h>
using namespace std;

void subsequences(string s, int i, string ans) {
    if (i == s.length()) {
        cout << ans << endl;
        return;
    }

    // Choice 1: Include the current character
    subsequences(s, i + 1, ans + s[i]);

    // Choice 2: Exclude the current character
    subsequences(s, i + 1, ans);
}

int main() {
    string s;
    cin >> s;

    subsequences(s, 0, "");
}