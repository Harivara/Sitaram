Approach
Do a Dijkstra with the state (i, j, t), where:
i = row index
j = column index
t = number of teleportations so far
Do a normal right and down move.
When we are at t teleportations and can teleport to a cell (x, y), we shouldn't acknowledge the existence of (x, y) again at a later time with the same or higher teleport count because it wouldn't be beneficial. So, delete that teleport edge after traversing it. This is vital for the correct time complexity.
Complexity
Time complexity: O(nmklognmk)
Space complexity: O(nmk)
Tiny proof for time complexity
The setup can be proven to have a complexity of O(nmk+nmlognm)
There are nmk vertices.
There are at most 2 edges for down and right moves for each vertex, leading to a total of 2 * nmk edges.
There are a total of nmk teleport destinations. Since we delete a teleport destination after it has been traversed once, there are nmk teleport edges in total.
Therefore, the upper bound for number of edges is 2nmk+nmk=3nmk
Dijkstra with binary heap takes O((E+V)logV).
O((E+V)logV)
= O((3nmk+nmk)lognmk)
= O(4nmklognmk)
= O(nmklognmk)
Because nmlog(nm)≤nmklog(nmk) is always true for positive integers, then the total complexity is O(nmk+nmlognm)+O(nmklognmk)=O(nmklognmk)



https://leetcode.com/contest/biweekly-contest-163/problems/minimum-cost-path-with-teleportations/description/


class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<tuple<int, int, int>> vals(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vals[i * m + j] = {grid[i][j], i, j};
            }
        }
        sort(vals.rbegin(), vals.rend());
        vector available(k, vals);

        
        using tr = tuple<int, int, int, int>;
        priority_queue<tr, vector<tr>, greater<>> pq;
        vector shortest(n, vector(m, vector<int>(k + 1, INT_MAX/2)));
        pq.push({shortest[0][0][0] = 0, 0, 0, 0});

        while(!pq.empty()) {
            auto [cost, i, j, t] = pq.top();
            pq.pop();
            if(cost > shortest[i][j][t] || (t > 0 && cost >= shortest[i][j][t - 1])) continue;
            if(i == n - 1 && j == m - 1) return cost;

            if(i + 1 < n) {
                int newCost = cost + grid[i + 1][j];
                if(newCost < shortest[i + 1][j][t]) {
                    pq.push({shortest[i + 1][j][t] = newCost, i + 1, j, t});
                }
            }
            
            if(j + 1 < m) {
                int newCost = cost + grid[i][j + 1];
                if(newCost < shortest[i][j + 1][t]) {
                    pq.push({shortest[i][j + 1][t] = newCost, i, j + 1, t});
                }
            }

            if(t < k) {
                while(!available[t].empty() && get<0>(available[t].back()) <= grid[i][j]) {
                    auto& [_, ni, nj] = available[t].back();
                    if(cost < shortest[ni][nj][t + 1]) {
                        pq.push({shortest[ni][nj][t + 1] = cost, ni, nj, t + 1});
                    }
                    available[t].pop_back();
                }
                for(int p = t+1; p < k; p++) {
                    while(!available[p].empty() && get<0>(available[p].back()) <= grid[i][j]) {
                        available[p].pop_back();
                    }
                }
            }
        }
        unreachable();
    }
};



Hello

// DP TOPDOWN

#define FOR(i,a,b) for (int i = a ; i < b ; ++i)
class Solution {
public:
  void solve(vector<vector<int>> &curr, vector<vector<int>> &grid) {
    int n = grid[0].size(), m = grid.size();
    curr[0][0] = 0;
    FOR(i,0,m) FOR(j,0,n) {
      if (i > 0) curr[i][j] = min(curr[i][j], curr[i-1][j] + grid[i][j]);
      if (j > 0) curr[i][j] = min(curr[i][j], curr[i][j-1] + grid[i][j]);
    }
  }

  const int INF = 1e9;

  int minCost(vector<vector<int>>& grid, int k) {
    int n = grid[0].size(), m = grid.size();
    vector<vector<int>> prev(m, vector<int>(n, INF)), curr(m, vector<int>(n, INF));
    
    // Coordinate compression
    vector<int> A;
    unordered_map<int,int> MP;
    FOR(i,0,m) FOR(j,0,n) A.push_back(grid[i][j]);
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for (int i = 0, sz = A.size(); i < sz; ++i) MP[A[i]] = i;
    int sz = A.size();

    // Initial DP without teleports
    solve(prev, grid);
    int ans = prev[m-1][n-1];

    // Allow teleports one by one
    for (int t = 1; t <= k; ++t) {
      vector<int> best(sz, INF);
      curr.assign(m, vector<int>(n, INF));

      // Step 1: best for exact values
      FOR(i,0,m) FOR(j,0,n)
        best[MP[grid[i][j]]] = min(best[MP[grid[i][j]]], prev[i][j]);

      // Step 2: suffix-min to cover all >= values
      for (int i = sz - 2; i >= 0; --i)
        best[i] = min(best[i], best[i+1]);

      // Step 3: update with teleport landing
      FOR(i,0,m) FOR(j,0,n)
        curr[i][j] = min(prev[i][j], best[MP[grid[i][j]]]);

      // Step 4: spread via normal moves
      solve(curr, grid);

      prev.swap(curr);
      ans = prev[m-1][n-1];
    }
    return ans;
  }
};