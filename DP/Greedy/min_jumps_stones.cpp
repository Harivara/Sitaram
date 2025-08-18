https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A) {

    if(A.size()==1) return 0;

    vector<int> dp(A.size(),0);

    for(int i=0;i<A.size();i++){

        if(i==0) dp[i]=A[0];

        else dp[i]=max(dp[i-1],A[i]+i);

    }

    int count=1,high=dp[0];

    while(high<A.size()-1){

        count++;
         if(high==dp[high]) return -1;     //[3,2,1,0,4]  dp[3,3,3,3,8]  high=3 high==dp[high]
                                                                              //(3==3)
        else high=dp[high];

    }

    return count;

}