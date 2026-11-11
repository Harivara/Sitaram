
#include <bits/stdc++.h>
using namespace std;

void solve(int row, int n,
           vector<string>& board,
           vector<vector<string>>& ans,
           vector<int>& col,
           vector<int>& diagonal1,
           vector<int>& diagonal2) {

    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {

        int d1 = row - c + n - 1;
        int d2 = row + c;

        // Check column and both diagonals in O(1)
        if (col[c] || diagonal1[d1] || diagonal2[d2])
            continue;

        // Place queen
        board[row][c] = 'Q';
        col[c] = 1;
        diagonal1[d1] = 1;
        diagonal2[d2] = 1;

        solve(row + 1, n, board, ans,
              col, diagonal1, diagonal2);

        // Backtrack
        board[row][c] = '.';
        col[c] = 0;
        diagonal1[d1] = 0;
        diagonal2[d2] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    vector<int> col(n, 0);

    // There are 2*n - 1 diagonals in each direction
    vector<int> diagonal1(2 * n - 1, 0);
    vector<int> diagonal2(2 * n - 1, 0);

    solve(0, n, board, ans, col, diagonal1, diagonal2);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);

    for (const auto& board : ans) {
        for (const auto& row : board)
            cout << row << '\n';

        cout << '\n';
    }

    return 0;
}
