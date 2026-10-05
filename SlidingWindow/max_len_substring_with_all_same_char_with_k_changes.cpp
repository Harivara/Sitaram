

#include<bits/stdc++.h>
using namespace std;

int characterReplacement(int n, int k,string s){
    //write code here
    vector<int>freq(26,0);
    int left=0;
    int maxchar=0;
    int ans=0;
    for(int right=0;right<n;right++){
        freq[s[right]-'a']++;
        maxchar=max(maxchar,freq[s[right]-'a']);
        int changes=right-left+1-maxchar;

        if(changes>k){
            freq[s[left]-'a']--;
            left++;
        }

        ans=max(ans,right-left+1);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = characterReplacement(n,k,s);
    cout<<ans<<"\n";
    return 0;
}