https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string A) {
    int n = A.size();
    stack<int> st;
    st.push(-1);  // base for first valid substring
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == '(') {
            st.push(i);
        } else {
            st.pop();  // pop the last '(' index
            if (!st.empty()) {
                maxLen = max(maxLen, i - st.top());
            } else {
                st.push(i);  // reset the base
            }
        }
    }
    return maxLen;
}
