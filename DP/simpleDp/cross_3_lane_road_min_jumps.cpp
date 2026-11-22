https://leetcode.com/problems/minimum-sideway-jumps/?utm_source=chatgpt.com

class Solution {
public:

    int fun(int i, int n, vector<int>& obstacles, int curr,vector<vector<int>>&dp) {

        if(i == n-1) {
            return 0;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }

        if(obstacles[i+1] != curr) {
            return dp[i][curr]= fun(i+1, n, obstacles, curr,dp);
        }

        int jumps = 1e9;

        for(int lane = 1; lane <= 3; lane++) {

            if(curr != lane && obstacles[i] != lane &&
               obstacles[i+1] != lane) {

                int jump = 1 + fun(i+1, n, obstacles, lane,dp);

                jumps = min(jumps, jump);
            }
        }

        return dp[i][curr]= jumps;
    }

    int minSideJumps(vector<int>& obstacles) {

        int n = obstacles.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));

        return fun(0, n, obstacles, 2,dp);
    }
};