https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/description/


class Solution {
public:
    using ll = long long;
    ll f(ll i, ll j, ll parity, vector<vector<int>>& waitCost, vector<vector<vector<ll>>>& dp){
        if(i == waitCost.size()-1 && j == waitCost[0].size()-1) return 0;
        if(i == waitCost.size() || j == waitCost[0].size()) return 1e15;
        if(dp[i][j][parity] != -1) return dp[i][j][parity];

        ll ans = LLONG_MAX;
        if(parity%2 == 1){
            ans = min(ans, (i + 2)*(j + 1) + f(i + 1, j, 0, waitCost, dp));
            ans = min(ans, (i + 1)*(j + 2) + f(i, j + 1, 0, waitCost, dp));
        } else ans = min(ans, waitCost[i][j] + f(i, j, 1, waitCost, dp));

        return dp[i][j][parity] = ans;
    }
    
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>> (n, vector<ll> (2, -1)));
        return 1 + f(0, 0, 1, waitCost, dp);
        //added 1 because function started for entering (0,0) so cost to enter (0,0) is (0+1)*(0+1)=1
    }
};

class Solution {
public:
    using ll = long long;
    ll INF = 1e15;

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<ll> nextEvenSecond(n + 1, INF), nextOddSecond(n, INF);
        vector<ll> currEvenSecond(n + 1, INF), currOddSecond(n, INF);

        currOddSecond[n-1] = 0;
        currEvenSecond[n-1] = 0;

        for(int row = m - 1; row >= 0; row--){
            for(int col = n - 1; col >= 0; col--){
                if(row == m - 1 && col == n - 1) continue;
                
                ll moveDown = (ll)(row + 2) * (col + 1) + nextEvenSecond[col];
                ll moveRight = (ll)(row + 1) * (col + 2) + currEvenSecond[col + 1];

                currOddSecond[col] = min(moveDown, moveRight);
                currEvenSecond[col] = waitCost[row][col] + currOddSecond[col];
            }
            nextEvenSecond = currEvenSecond;
            nextOddSecond = currOddSecond;
        }

        return 1 + nextOddSecond[0];
    }
};