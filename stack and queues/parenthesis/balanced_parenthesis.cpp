https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string A) {
    stack<char>s;
    for(int i=0;i<A.length();i++){
        if(A[i]=='('){
            s.push(A[i]);
        }
        else{
            if(!s.empty()){
                if(s.top()!='('){
                    return 0;
                }
                else{
                    s.pop();
                }
            }
            else{
                return 0;
            }
        }
    }
        return s.empty();
}
