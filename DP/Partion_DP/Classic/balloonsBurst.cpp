//PartionDP Template solution

// The index K is the last removed balloons with the boundaries [i,j];
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //including the nums[-1] and nums[n]
        int n = nums.size() + 2;        
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> new_nums(n, 1);
        int i = 1;
        for(auto num : nums) {
            new_nums[i++] = num;
        }
        for(int len = 2; len <n; len++) { 
            //iterate from interval length from 2 to n
            for(int i = 1; i+len-1 <n ; i++) {
                int j = i + len - 1;
                //select between left and right boundary (i, j)
                for(int k = i; k < j; k++) { 
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + new_nums[i-1] * new_nums[k] * new_nums[j]);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[1][n - 1];
    }
};



// Instead of choosing which balloon to burst first, we choose which balloon to burst LAST.

// https://leetcode.com/problems/burst-balloons/

class Solution {
public:
int fun(int i,int j,vector<int>&nums){
    if(i>j){
        return 0;
    }
    int mini=INT_MIN;
    for(int ind=i;ind<=j;ind++){
        int cost=(nums[i-1]*nums[ind]*nums[j+1])+fun(i,ind-1,nums)+fun(ind+1,j,nums);
        mini=max(cost,mini);
    }
    return mini;

}
    int maxCoins(vector<int>& nums) {
        int k=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return fun(1,k,nums);
    //     vector<vector<int>>dp(k+2,vector<int>(k+2,0));
    //     for(int i=k;i>=1;i--){
    //         for(int j=1;j<=k;j++){
    //             if(i>j){
    //                 continue;
    //             }
    //               int mini=-1e9;
    // for(int ind=i;ind<=j;ind++){
    //     int cost=(nums[i-1]*nums[ind]*nums[j+1])+dp[i][ind-1]+dp[ind+1][j];
    //     mini=max(cost,mini);
    // }
    // dp[i][j]=mini;
    //         }
    //     }
    // return dp[1][k];
    }
};