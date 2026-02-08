// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  public:
  void fun(int open, int close, int n,vector<string>&v, string s){
      if(open==n && close==n){
          v.push_back(s);
      }
      if(open<n){
          fun(open+1,close,n,v,s+"(");
      }
      if(close<open){
          fun(open,close+1,n,v,s+")");
      }
      return;
      
  }
    vector<string> generateParentheses(int n) {
        // code here
        vector<string>v;
        if(n%2!=0){
            return v;
        }
        int open=n/2,close=n/2;
        fun(0,0,n/2,v,"");
        return v;
        
    }
};