#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findPairs(vector<int>& arr, int diff) {
    sort(arr.begin(), arr.end());

    vector<pair<int,int>> ans;

    int left = 0, right = 1;

    while (right < arr.size()) {
        int d = arr[right] - arr[left];

        if (d == diff) {
            ans.push_back({arr[left], arr[right]});
            left++;
            right++;
        }
        else if (d < diff) {
            right++;
        }
        else {
            left++;
        }

        // Keep right ahead of left
        if (left == right)
            right++;
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2, 6};

    vector<pair<int,int>> ans = findPairs(arr, 2);

    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}