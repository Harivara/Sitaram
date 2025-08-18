https://leetcode.com/problems/minimum-time-to-activate-string/description/

// Cann't use the template as the final answer sometimes return -1 and it cannot be posibble if we return left; 

class Solution {
public:

    bool isValid(string s, vector<int>& order, int k, int t) {
        for(int i = 0; i <= t; i++) {
            s[order[i]] = '*';
        }
        int n = order.size(), idxStar = -1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                idxStar = i;
            }
            if (idxStar != -1) {
                sum += (long long)idxStar + 1;
            }
        }
        return sum >= (long long)k;
    }
    
    int minTime(string s, vector<int>& order, int k) {
        int n = order.size(), left = 0, right = n-1, ans = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(isValid(s, order, k, mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};