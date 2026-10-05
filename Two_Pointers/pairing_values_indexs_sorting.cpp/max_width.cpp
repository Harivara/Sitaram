


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int minIndex = n;
        int ans = 0;

        for(int j = 0; j < n; j++) {
            minIndex = min(minIndex, v[j].second);

            ans = max(ans, v[j].second - minIndex);
        }

        return ans;
    }
};