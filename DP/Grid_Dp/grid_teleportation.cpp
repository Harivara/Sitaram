https://leetcode.com/contest/weekly-contest-450/problems/grid-teleportation-traversal/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (matrix[0][0] == '#' || matrix[n - 1][m - 1] == '#') return -1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        unordered_map<char, vector<pair<int, int>>> teleport;
        unordered_set<char> usedTeleport;

        // collect teleporters
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (isalpha(matrix[i][j]) && matrix[i][j] != '#')
                    teleport[matrix[i][j]].push_back({i, j});

        dq.push_front({0, 0});
        dist[0][0] = 0;

        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            int curDist = dist[x][y];

            if (x == n - 1 && y == m - 1)
                return curDist;

            // move in 4 directions (cost = 1)
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    matrix[nx][ny] != '#' && dist[nx][ny] > curDist + 1) {
                    dist[nx][ny] = curDist + 1;
                    dq.push_back({nx, ny});
                }
            }

            // teleport (cost = 0)
            char ch = matrix[x][y];
            if (isalpha(ch) && !usedTeleport.count(ch)) {
                usedTeleport.insert(ch);
                for (auto& [tx, ty] : teleport[ch]) {
                    if (dist[tx][ty] > curDist) {
                        dist[tx][ty] = curDist;
                        dq.push_front({tx, ty});
                    }
                }
            }
        }

        return -1;
    }
};
©leetcode