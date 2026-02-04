class Solution {
  public:
   double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n=val.size();
        
        vector<pair<double,int>>items;
        
        for(int i=0;i<n;i++){
            items.push_back({double(val[i])/wt[i] , i});
        }
        
        sort(items.begin(),items.end(),greater<pair<double,int>>());
        
        int total_wt=0;
        double total_val=0;
        
        for(int i=0;i<n;i++){
            int idx=items[i].second;
            if(total_wt + wt[idx] <= capacity){
                total_wt+=wt[idx];
                total_val+=val[idx];
            }
            else{//total_wt + wt[idx] > capacity
                //take fraction
                int remain=capacity - total_wt;
                total_val+=items[i].first * remain;//rate per wt * remaining wt 
                break;
            }
        }
        return total_val;
    }
};
