#include<bits/stdc++.h>
using namespace std;

int fun(int ind,vector<int>&arr,int k,int n,int prev){
    if(k==1){
        int count;
        for(int i=0;i<=ind;i++){
            if(prev%arr[i]==0){
                count++;
            }
        }
        return count;
    }
    int notpick=fun(ind-1,arr,k,n,prev);
    int pick=0;
    if(prev==-1 || prev%arr[ind]==0){
        prev=arr[ind];
        pick=fun(ind,arr,k-1,n,prev);
    }
    return (pick+notpick)%10000;

}
int main(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    return fun(n-1,arr,k,n,-1);

}