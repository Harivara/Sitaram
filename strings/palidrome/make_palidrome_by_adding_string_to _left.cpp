// https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
public:

    string shortestPalindrome(string s) {
      string rev=s;
      reverse(rev.begin(),rev.end());
      string combined=s+"$"+rev;
      vector<int>lps(combined.size(),0);
      int i=1;
      int len=0;
      while(i<combined.size()){
        if(combined[i]==combined[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                i++;
                lps[len]=0;
            }
            else{
                len=lps[len-1];
            }
        }
      }  
      int count=lps.back();
      string join=s.substr(count);
      reverse(join.begin(),join.end());
      return join+s;
    }
};


// NOTE:
// The lps array doesnot give the longest palidrome 
// but the prefix of the palidrome
// Ex: aabba --> longest palidrome "abba" converting --> "abbaaabba"
//     aabba --> palidrome prefix  "aa"   converting --> "abbaabba"