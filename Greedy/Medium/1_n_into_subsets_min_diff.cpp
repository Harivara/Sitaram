https://www.geeksforgeeks.org/dsa/divide-1-n-two-groups-minimum-sum-difference/

#include <bits/stdc++.h>
using namespace std;

// Function to divide the elements from 1
// to n in two groups with minimum difference
vector<vector<int>> findGroup(int n) {

    // to store the two groups
    vector<vector<int>> res(2);

    // to store the sum of both groups
    int sum1 = 0, sum2 = 0;

    // find half of sum of elements from 1 to n
    int half = n * (n + 1) / 4;

    for(int i = n; i >= 1; i--) {

        // if adding the current element to first
        // group doesn't exceed half, add it
        if(sum1 + i <= half) {
            res[0].push_back(i);
            sum1 += i;
        }

        // else add it to the second group
        else {
            res[1].push_back(i);
            sum2 += i;
        }
    }

    return res;
}

int main() {
    int n = 7;
    vector<vector<int>> res = findGroup(n);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}