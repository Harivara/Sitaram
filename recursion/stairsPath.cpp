#include <bits/stdc++.h>
using namespace std;

void fun(int remaining, vector<vector<int>>& ans, vector<int>& curr) {
    if (remaining == 0) {
        ans.push_back(curr);
        return;
    }

    if (remaining < 0) return;

    // Take step 1
    curr.push_back(1);
    fun(remaining - 1, ans, curr);
    curr.pop_back();

    // Take step 2
    curr.push_back(2);
    fun(remaining - 2, ans, curr);
    curr.pop_back();

    // Take step 3
    curr.push_back(3);
    fun(remaining - 3, ans, curr);
    curr.pop_back();
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans;
    vector<int> curr;

    fun(n, ans, curr);

cout<<"[";
   //  for (auto& seq : ans) {
   //      for (int x : seq) {
   //          cout << x;
   //      }
   //      cout<<", ";
   //  }
   for(int i=0;i<ans.size();i++){
      for(int j=0;j<ans[i].size();j++){
         cout<<ans[i][j];
      }
      if(i!=ans.size()-1){
         cout<<", ";
      }
   }
cout<<"]";



    return 0;
}