// Find the permutations of a number withno leading zero


#include <bits/stdc++.h>
using namespace std;

void permute(int start,vector<int>&digits){
    if(start==digits.size()){
        if(digits[0]==0) return;  // SKIP LEADING ZEROS
            long long num=0;
            for(int d:digits){
                num=num*10+d;
            }
            cout<<num<<endl;
            return;
    }
    for(int i=start;i<digits.size();i++){
        swap(digits[start],digits[i]);
        permute(start+1,digits);
        swap(digits[i],digits[start]);

    }
}

int main(){
    int n=5000;
    vector<int>digits;
    while(n>0){
        digits.push_back(n%10);
        n=n/10;
    }
    permute(0,digits);
    return 0;
}
