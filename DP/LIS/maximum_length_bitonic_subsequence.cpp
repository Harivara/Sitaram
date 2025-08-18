https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &A) {

   
    int n=A.size();
    if(n==0){
        return 0;
    }
  
    int lis[n+1];
    int lds[n+1];
        lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    lds[n-1]=1;
    for(int i=n-2;i>=0;i--){
        lis[i]=1;
        for(int j=n-1;j>i;j--){
            if(A[i]>A[j]){
                lds[i]=max(lds[i],lds[j]+1);
            }
        }
    }

 
    int res=0;
    for(int i=0;i<n;i++){
        res=max(lis[i]+lds[i]-1,res);
    }
    return res;
}


    

