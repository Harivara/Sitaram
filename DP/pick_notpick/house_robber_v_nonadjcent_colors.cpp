class Solution {
public:

    long long fun(int i, vector<int>& nums, vector<int>& colors) {

        if(i < 0) return 0;

        long long notPick = fun(i-1, nums, colors);

        long long pick = nums[i];

        if(i > 0 && colors[i] == colors[i-1]) {
            pick += fun(i-2, nums, colors);
        }
        else {
            pick += fun(i-1, nums, colors);
        }

        return max(pick, notPick);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        // return fun(n-1, nums, colors);
        vector<long long>dp(n+1,0);
        for(int i=1;i<=n;i++){
            long long notpick=dp[i-1];
            long long pick=nums[i-1];
            if(i>1 && colors[i-1]==colors[i-2]){
                pick+=dp[i-2];
            }
            else{
                pick+=dp[i-1];
            }
            dp[i]=max(pick,notpick);
        }
        return dp[n];
    }
};