https://www.interviewbit.com/problems/palindrome-partitioning-ii/

bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

int fun(int ind, string &A, int n, vector<int> &dp) {
    if (ind == n) return 0;
    if (dp[ind] != -1) return dp[ind];

    int mincost = INT_MAX;
    for (int j = ind; j < n; j++) {
        if (isPalindrome(A, ind, j)) {
            int cost = 1 + fun(j + 1, A, n, dp);
            mincost = min(mincost, cost);
        }
    }
    return dp[ind] = mincost;
}

int Solution::minCut(string A) {
    int n = A.length();
    // vector<int> dp(n + 1, -1);
    // return fun(0, A, n, dp) - 1; // subtract 1 because last partition doesn't need a cut
    vector<int> dp(n + 1, 0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(A,i,j)){
                int cost=1+dp[j+1];
                mincost=min(cost,mincost);
            }
        }
        dp[i]=mincost;
    }
    return dp[0]-1;
}
