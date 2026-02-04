class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int total_sum=0;
        for(int i:arr){
            total_sum+=i;
        }
        
        int target;
        if(total_sum%2!=0){
            return false;
        }
        else{
            target=total_sum/2;
        }
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        
        if(arr[0]<=target){
            dp[0][arr[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int notpick=dp[i-1][j];
                int pick=false;
                if(arr[i]<=j){
                    pick=dp[i-1][j-arr[i]];
                }
                dp[i][j]=(pick || notpick);
            }
        }
        return dp[n-1][target];
    }
};