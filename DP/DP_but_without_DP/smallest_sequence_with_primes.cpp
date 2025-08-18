https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/




class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int x=0, y=0, z=0;
        for(int i=1; i<n; i++){
            dp[i] = min(dp[x]*2, min(dp[y]*3, dp[z]*5));
            if(dp[i] == 2*dp[x]) x++;
            if(dp[i] == 3*dp[y]) y++;
            if(dp[i] == 5*dp[z]) z++;
        }
        return dp[n-1];
    }
};

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    res.push_back(1);
    int iA = 0,iB = 0,iC = 0;
    
    for(int i = 0 ;i<D;i++){
        int nextA = res[iA] * A;
        int nextB = res[iB] * B;
        int nextC = res[iC] * C;
        int nextN = min(nextA,min(nextB,nextC));
        
        if(nextN == nextA)
        iA++;
        
        if(nextN == nextB)
        iB++;
        
        if(nextN == nextC)
        iC++;
        
        res.push_back(nextN);
    }
   res.erase(res.begin());
}

