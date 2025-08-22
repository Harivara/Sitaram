// https://www.interviewbit.com/problems/merge-elements/

#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
    int n=A.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    vector<int>prefixsum(n+1,0);

    for(int i=1;i<n+1;i++){
        prefixsum[i]=prefixsum[i-1]+A[i-1];
    }
    for(int diff=1;diff<n;diff++){
        int i=0;
        int j=i+diff;   
        for(;j<n;j++,i++){
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],prefixsum[j+1]-prefixsum[i]+dp[i][k]+dp[k+1][j]);
            }
        }
    }
    return dp[0][n-1];
}
    //     i = 0     j = 3
//     (0,0) + (1,3) -> (i,k) + (k+1,j)
//     prefix[1] - prefix[0] + prefix[4] - prefix[1] + dp[0][0] + dp[1][3]

//     (0,1) + (2,3)
//     prefix[2] - prefix[0] + prefix[4] - prefix[2] + dp[0][1] + dp[2][3]

//     (0,2) + (3,3)
//     prefix[3] - prefix[0] + prefix[4] - prefix[3] + dp[0][2] + dp[3][3]

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<solve(vec);
    return 0;

}
