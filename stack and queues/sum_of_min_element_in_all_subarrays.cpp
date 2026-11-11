
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarraySum(vector<int>& arr, int n) {
        const long long MOD = 1000000007;
        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || arr[st.top()] >= arr[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long leftCount = mid - left;
                long long rightCount = right - mid;

                long long contribution =
                    (arr[mid] * leftCount) % MOD;

                contribution = (contribution * rightCount) % MOD;

                ans = (ans + contribution) % MOD;
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.minSubarraySum(arr, n) << '\n';

    return 0;
}
