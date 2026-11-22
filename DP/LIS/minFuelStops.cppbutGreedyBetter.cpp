
// dp[i][j] = Maximum amount of fuel remaining after considering the first i stations and making exactly j refueling stops.

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=startFuel;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]=dp[i-1][j];
                
                if(dp[i-1][j-1]>=stations[i-1][0]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[i-1][1]);
                }
            }
        }
        for(int j=0;j<=n;j++){
            if(dp[n][j]>=target){
                return j;
            }
        }
        return -1;
    }
};



class Solution {
public:

    long long fun(int i, int j, vector<vector<int>>& stations,
                  int startFuel, vector<vector<long long>>& dp) {

        if(j == 0) {
            return startFuel;
        }

        if(i == 0 || j > i) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Not pick current station
        long long notPick = fun(i-1, j, stations, startFuel, dp);

        // Pick current station
        long long pick = 0;

        long long prev = fun(i-1, j-1, stations, startFuel, dp);

        if(prev >= stations[i-1][0]) {
            pick = prev + stations[i-1][1];
        }

        return dp[i][j] = max(pick, notPick);
    }

    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {

        int n = stations.size();

        vector<vector<long long>> dp(
            n+1, vector<long long>(n+1, -1)
        );

        for(int j = 0; j <= n; j++) {

            if(fun(n, j, stations, startFuel, dp) >= target) {
                return j;
            }
        }

        return -1;
    }
};
