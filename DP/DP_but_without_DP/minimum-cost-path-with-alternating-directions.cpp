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
    struct State {
        int i, j, time;
        long long cost;
        bool operator>(const State& other) const {
            return cost > other.cost;
        }
    };

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));
        priority_queue<State, vector<State>, greater<State>> pq;

        // Start at (0, 0) at time = 1 (odd), entry cost = (0+1)*(0+1) = 1
        dist[0][0][1] = 1;
        pq.push({0, 0, 1, 1});

        while (!pq.empty()) {
            auto [i, j, time, cost] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1) return cost;

            int parity = time % 2;

            if (parity == 0) {
                // Even second → must wait
                long long newCost = cost + waitCost[i][j];
                if (newCost < dist[i][j][1]) {
                    dist[i][j][1] = newCost;
                    pq.push({i, j, time + 1, newCost});
                }
            } else {
                // Odd second → can move to right or down
                vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
                for (auto [di, dj] : dirs) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < m && nj < n) {
                        long long moveCost = (ni + 1) * (nj + 1);
                        long long newCost = cost + moveCost;
                        if (newCost < dist[ni][nj][0]) {
                            dist[ni][nj][0] = newCost;
                            pq.push({ni, nj, time + 1, newCost});
                        }
                    }
                }
            }
        }

        return -1; // Should not reach here
    }
};


typedef long long ll;

class Solution {
public:
    // Utility to check if a cell is within bounds
    bool check(ll i, ll j, ll m, ll n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    vector<ll> drow{0, 1}; // Right and Down directions
    vector<ll> dcol{1, 0};

    ll minCost(int m, int n, vector<vector<int>>& waitCost) {
        // Min-heap to store {cost, {row, col}}
        priority_queue<
            pair<ll, pair<ll, ll>>,
            vector<pair<ll, pair<ll, ll>>>,
            greater<pair<ll, pair<ll, ll>>>>
            pq;

        // Initialize cost matrix
        vector<vector<ll>> cost(m, vector<ll>(n, LLONG_MAX));
        cost[0][0] = 0;

        pq.push({1, {0, 0}}); // Start at (0,0) with travel cost = 1

        while (!pq.empty()) {
            ll cst = pq.top().first;
            ll x = pq.top().second.first;
            ll y = pq.top().second.second;
            pq.pop();

            for (ll k = 0; k < 2; k++) {
                ll r = x + drow[k];
                ll c = y + dcol[k];

                if (check(r, c, m, n)) {
                    // Base cost = travel cost
                    ll temp = cst + (r + 1) * (c + 1);

                    // Add wait cost unless it's destination
                    if (r != m - 1 || c != n - 1)
                        temp += waitCost[r][c];

                    // Relaxation step
                    if (temp < cost[r][c]) {
                        cost[r][c] = temp;
                        pq.push({temp, {r, c}});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};