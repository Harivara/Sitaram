#include <bits/stdc++.h>
using namespace std;

int MaxSum(vector<int> arr, int n) {

    // Normal Kadane
    int currMax = arr[0];
    int maxSum = arr[0];

    // Minimum Kadane
    int currMin = arr[0];
    int minSum = arr[0];

    int total = arr[0];

    for (int i = 1; i < n; i++) {

        currMax = max(arr[i], currMax + arr[i]);
        maxSum = max(maxSum, currMax);

        currMin = min(arr[i], currMin + arr[i]);
        minSum = min(minSum, currMin);

        total += arr[i];
    }

    // All elements are negative
    if (maxSum < 0)
        return maxSum;

    // Maximum wrapping subarray
    int circularSum = total - minSum;

    return max(maxSum, circularSum);
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << MaxSum(arr, n);

    return 0;
}