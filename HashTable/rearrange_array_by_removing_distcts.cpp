https://leetcode.com/contest/weekly-contest-521/problems/rearrange-array-by-removing-distinct-values/


// for(auto &it : mp){
//     ...
//     mp.erase(it.first);
// }

// Using this is wrong
// This is unsafe because it is an iterator/reference 
// to an element that you just erased. After:

// mp.erase(it.first);

// it becomes invalid, but the range-based loop still tries 
// to move to the next element.



// USE ITERATOR TO REMOVE THE ELEMENT IN MAP LOOP

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        while (mp.size() != 0) {
            for (auto it = mp.begin(); it != mp.end();) {

                int value = it->first;

                ans.push_back(value);

                it->second--;

                if (it->second == 0) {
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }
        }
        return ans;
    }
};