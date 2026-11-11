# include <bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col, vector<string>&board, vector<vector<string>>&ans){
    int n=board[0].length();
    for(int r=row-1;r>=0;r--){
        if(board[r][col]=='Q'){
            return false;
        }
    }

    for(int r=row-1,c=col-1;r>=0 && col>=0;r--,c--){
        if(board[r][c]=='Q'){
            return false;
        }
    }
    for(int r=row-1, c=col+1; r>=0 && c<n; r--,c++){
        if(board[r][c]=='Q'){
            return false;
        }
    }
    return true;
}

void fun(int row, int n, vector<string>&board, vector<vector<string>>&ans){
    if(row==n){
        ans.push_back(board);
        return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(row,col, board,ans)){
            board[row][col]='Q';
            fun(row+1,n,board,ans);
            board[row][col]='.';
        }
    }
}

class Solution {
public:
    int totalNQueens(int n) {
        // write code here
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        fun(0,n,board,ans);
    return ans.size();
    }
};

int main() {
    int n;
	cin>>n;
	Solution Obj;
	cout<<Obj.totalNQueens(n);
    return 0;
}