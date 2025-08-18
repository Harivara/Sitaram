https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
bool feasible(int capacity,vector<int>piles,int h){
    
    int count=0;
    for(int i=0;i<piles.size();i++){
        if(piles[i]%capacity==0){
            count=count+(piles[i]/capacity);
        }
        else{
            count=count+(piles[i]/capacity)+1;
        }
        if(count>h){
            return false;
        }
        
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=0;
        for(int i=0;i<piles.size();i++){
            right=max(right,piles[i]);
        }
        while(left<right){
            int mid=(left+right)/2;
            if(feasible(mid,piles,h)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};