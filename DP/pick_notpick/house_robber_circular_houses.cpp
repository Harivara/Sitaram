class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp1(n+2,0);
      vector<int>dp2(n+2,0);
      
      for(int i=n-1;i>=1;i--){
        int pick=nums[i]+dp1[i+2];
        int notpick=dp1[i+1];
        dp1[i]=max(pick,notpick);

        // pick=nums[i-1]+dp2[i+2-1];
        // notpick=dp2[i+1-1];
        // dp2[i-1]=max(pick,notpick);
        
      }
    
    for(int i=n-2;i>=0;i--){
        int pick=nums[i]+dp2[i+2];
        int notpick=dp2[i+1];
        dp2[i]=max(pick,notpick);
    }
    return max(dp1[1],dp2[0]);

    }
};