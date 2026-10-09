// add string and pop_back while pushing string into the recurssive funtion



#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void aMazePaths(int n, int m, string &psf, int i, int j){
       if(i==n && j==m){
            cout<<psf<<endl;
            return;
       }
       if(i>n || j>m){
        return;
       }
       if(j<m){
            psf+="h";
            aMazePaths(n,m,psf,i,j+1);
            psf.pop_back();
       }
       if(i<n){
        psf+="v";
        aMazePaths(n,m,psf,i+1,j);
        psf.pop_back();
       }
    }

};

int main()
{
    int n,m;
    cin>>n>>m;
    Solution ob;
    ob.aMazePaths(n,m,"",1,1);
    return(0);
}



