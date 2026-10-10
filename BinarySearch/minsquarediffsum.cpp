https://leetcode.com/problems/minimum-sum-of-squared-difference/?envType=daily-question&envId=2026-10-10


class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        int n = nums1.size();

        vector<long long> diff(n);

        long long k = (long long)k1 + k2;

        long long high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            high = max(high, diff[i]);
        }

        long long low = 0;

        // Find the minimum possible maximum difference
        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long required = 0;

            for (long long d : diff) {
                if (d > mid) {
                    required += d - mid;
                }

                if (required > k)
                    break;
            }

            if (required <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long limit = low;

        // Reduce all differences greater than limit
        for (long long &d : diff) {
            if (d > limit) {
                k -= d - limit;
                d = limit;
            }
        }

        // If everything is already zero, we're done.
        if (limit == 0)
            return 0;

        // Remaining operations are less than the number
        // of elements currently at 'limit'.
        for (long long &d : diff) {
            if (k == 0)
                break;

            if (d == limit) {
                d--;
                k--;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};