https://www.interviewbit.com/problems/longest-increasing-subsequence/

int ceil(vector<int>&tail,int l,int r, int x){
    while(r>l){
        int m=(l+r)/2;
        if(tail[m]>=x){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    return r;
}
int Solution::lis(const vector<int> &A) {
    int n=A.size();
    vector<int>tail;
    if(n==1 || n==0){
        return n;
    }
    int len=1;
    tail.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(A[i]>tail[len-1]){
            tail.push_back(A[i]);
            len++;
        }
        else{
            // int c=lower_bound(tail.begin(),tail.end(),A[i])-tail.begin(); 
            int c=ceil(tail,0,len-1,A[i]);
            tail[c]=A[i];
        }
    }
    return len;
}

int Solution::lis(const vector<int> &A) {
    int n=A.size();
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=0;
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                lis[i]=max(lis[j]+1,lis[i]);
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,lis[i]);
    }
    return maxi;
    
}
