https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
bool feasible(int capacity, vector<int>weights, int days){
    int day=1;
    int total=0;
    for(int i=0;i<weights.size();i++){
        total=total+weights[i];
        if(total>capacity){
            total=weights[i];
            day++;
            if(day>days){
                return false;
            }
        }
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        int right=0;
        for(int i=0;i<weights.size();i++){
            left=max(left,weights[i]);
            right=right+weights[i];
        }
        while(left<right){
            int mid=(left+right)/2;
            if(feasible(mid,weights,days)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;

        
    }
};