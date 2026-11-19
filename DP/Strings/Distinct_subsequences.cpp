https://www.interviewbit.com/problems/distinct-subsequences/discussion/


// if a character matches we can consider it (dp[i-1][j-1]) or ignore it (dp[i-1][j])


// Given two sequences A, B, count number of unique ways in sequence A,
//  to form a subsequence that is identical to the sequence B.




int solve(int i, int j, string &A, string &B) {

    if (j == 0) return 1;

    if (i == 0) return 0;

    if (A[i - 1] == B[j - 1]) {
        return solve(i - 1, j - 1, A, B)
             + solve(i - 1, j, A, B);
    }

    return solve(i - 1, j, A, B);
}

int Solution::numDistinct(string A, string B) {
    return solve(A.length(), B.length(), A, B);
}



int Solution::numDistinct(string A, string B) {

    int n=A.length();
    int m=B.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    
    for(int i=0;i<=n;i++)dp[i][0]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
    
}




// Distinct subsequences with 1 mismatch
int fun(int i, int j, string &A, string &B, int prev) {

    if(j == 0) return 1;

    if(i == 0) return 0;

    int pick = 0;
    int notPick = 0;

    if(A[i-1] == B[j-1]) {

        // Exact match
        pick = fun(i-1, j-1, A, B, prev);

    }
    else if(prev == 1) {

        // Use the one allowed mismatch
        pick = fun(i-1, j-1, A, B, 0);
    }

    // Ignore current character of A
    notPick = fun(i-1, j, A, B, prev);

    return pick + notPick;
}