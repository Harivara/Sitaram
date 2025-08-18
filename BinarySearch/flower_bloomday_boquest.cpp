https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
 bool ispossible(int mid,int m,int k,vector<int>nums){
  
    long long flowers=0;
    long long boq=0;
    for(auto i:nums){
        if(i<=mid){
            flowers++;
            if(flowers==k){
                flowers=0;
                boq++;
            }
        }
        else{
            flowers=0;
        }
    }
    if(boq>=m){
        return true;
    }
    else{
       return false;
    }
 }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m>bloomDay.size()/k){
            return -1;
        }
        int left=1e9;
        int right=-1e9;
        for(auto i:bloomDay){
            left=min(left,i);
            right=max(right,i);
        }
        while(left<right){
            int mid=(left/2+right/2);
            if(ispossible(mid,m,k,bloomDay)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;

    }
};