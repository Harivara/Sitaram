// https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2026-10-05


class Solution {
public:
    int scoreOfParentheses(string s) {
        int curr=0;
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(curr);
                curr=0;
            }
            else{
                int lastscore=st.top();
                st.pop();
                curr=lastscore+max(curr*2,1);
            }
        }
        return curr;
    }
};