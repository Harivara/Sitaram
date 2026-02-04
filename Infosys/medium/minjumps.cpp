class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size(),0);
        if(arr.size()==1){
            return 0;
        }
        dp[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            dp[i]=max(dp[i-1],arr[i]+i);
        }
        for(int i:dp){
            cout<<i<<" ";
        }
        cout<<endl;
        
        int count=1;
        int high=dp[0];
        
        while(high<arr.size()-1){
            count++;
            if(high==dp[high]) return -1;
            else high=dp[high];
        }
        
        return count;
        
    }
};
