https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++) {
            int k = nums.size() - 1;
            int j = i + 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                    while(nums[k]==nums[k+1] && k<nums.size()-2){
                        k--;
                    }
                }
            }
        }
        return res;        
    }
};