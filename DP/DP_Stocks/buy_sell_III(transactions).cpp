https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int fun(int ind, int buy, int transaction, vector<int>A,vector<vector<vector<int>>>&dp){
    if(transaction<0){
        return 0;
    }
    if(ind==A.size()){
        return 0;
    }
    if(dp[ind][buy][transaction]!=-1){
        return dp[ind][buy][transaction];
    }
    int profit=0;
    if(buy){
        profit=max(-A[ind]+fun(ind+1,0,transaction,A,dp),0+fun(ind+1,1,transaction,A,dp));
    }
    else{
        profit=max(A[ind]+fun(ind+1,1,transaction-1,A,dp),fun(ind+1,0,transaction,A,dp));
    }
    return dp[ind][buy][transaction]=profit;
}
// int Solution::maxProfit(const vector<int> &A) {
//     vector<vector<vector<long long>>>dp(A.size()+1,vector<vector<long long>>(3,vector<long long>(3,0)));
//     // return fun(0,1,1,A,dp);
//     for(int i=A.size()-1;i>=0;i--){
//         for(int buy=0;buy<2;buy++){
//             for(int t=1;t<=2;t++){
//                 long long profit=0;
//                 if(buy==1){
//                     profit=max(-A[i]+dp[i+1][0][t],dp[i+1][1][t]);
//                 }
//                 else{
//                     profit=max(A[i]+dp[i+1][1][t-1],dp[i+1][0][t]);
//                 }
//                 dp[i][buy][t]=profit;
//             }
//         }
//     }
//     return dp[0][1][2];
// }

3D DP MEMORY EXCEEDED

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if (n == 0) return 0;

    vector<vector<long long>> ahead(2, vector<long long>(3, 0));
    vector<vector<long long>> curr(2, vector<long long>(3, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int t = 1; t <= 2; t++) {
                if (buy) {
                    curr[buy][t] = max(-A[i] + ahead[0][t], ahead[1][t]);
                } else {
                    curr[buy][t] = max(A[i] + ahead[1][t - 1], ahead[0][t]);
                }
            }
        }
        ahead = curr;
    }

    return ahead[1][2]; // Starting with buy allowed and 2 transactions left
}
