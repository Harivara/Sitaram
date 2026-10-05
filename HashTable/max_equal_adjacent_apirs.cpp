https://leetcode.com/contest/weekly-contest-521/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/submissions/2157636917/

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int>mp;
        int base=0;
        int bestgain=0;

        for(int i=1;i<nums.size();i++){
            int a=nums[i-1];
            int b=nums[i];

            if(a==b){
                base++;
            }
            else{
                if(a>b){
                    swap(a,b);
                }
                mp[{a,b}]++;
            }
        }

        for(auto &it:mp){
            bestgain=max(bestgain,it.second);
        }
        return bestgain+base;
    }
};