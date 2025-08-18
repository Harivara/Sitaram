https://leetcode.com/problems/reordered-power-of-2

class Solution {
public:

    bool istwopower(int n){
         return n > 0 && (n & (n - 1)) == 0;
    }
    void permute(int start,vector<int>&v,vector<int>&res){
        if(start==v.size()){
            if(v[0]==0){
                return;
            }
            int num=0;
            for(int i=0;i<v.size();i++){
                num=num*10+v[i];
            }
            res.push_back(num);

        }
        for(int i=start;i<v.size();i++){
            swap(v[start],v[i]);
            permute(start+1,v,res);
            swap(v[i],v[start]);
        }
    }
    bool reorderedPowerOf2(int n) {
        vector<int>v;
        while(n>0){
            v.push_back(n%10);
            n=n/10;
        }
        vector<int>res;
        permute(0,v,res);
        for(auto &x:res){
            if(istwopower(x)){
                return true;
            }
        }
        return false;
    }
};