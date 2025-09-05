https://leetcode.com/problems/number-of-perfect-pairs

class Solution {
public:
    struct Fenwick {
        vector<int> bit;
        int n;
        Fenwick(int n) : n(n) { bit.assign(n+1, 0); }
        void update(int i, int delta) {
            for (++i; i <= n; i += i & -i) bit[i] += delta;
        }
        int query(int i) {
            int s = 0;
            for (++i; i > 0; i -= i & -i) s += bit[i];
            return s;
        }
        int rangeQuery(int l, int r) {
            if (l > r) return 0;
            return query(r) - (l ? query(l-1) : 0);
        }
    };
    
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) arr[i] = abs(nums[i]);

        // Coordinate compression
        vector<long long> comp = arr;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        auto getId = [&](long long x) {
            return (int)(lower_bound(comp.begin(), comp.end(), x) - comp.begin());
        };

        Fenwick ft(comp.size());
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            long long x = arr[j];
            long long low = (x + 1) / 2;
            long long high = 2 * x;

            int L = (int)(lower_bound(comp.begin(), comp.end(), low) - comp.begin());
            int R = (int)(upper_bound(comp.begin(), comp.end(), high) - comp.begin()) - 1;

            ans += ft.rangeQuery(L, R);

            // Insert current element
            ft.update(getId(x), 1);
        }

        return ans;
    }
};
