https://www.interviewbit.com/problems/generate-all-parentheses/


bool compare(char a, char b){
    if(a=='(' && b==')' || a=='{' && b=='}' ||a=='[' && b==']'){
        return true;
    }
    else{
        return false;
    }
}
int Solution::isValid(string A) {
    stack<char> s;
    for(int i=0;i<A.length();i++){
        if(A[i]=='('||A[i]=='[' || A[i]=='{'){
            s.push(A[i]);
        }
        else{
            if(!s.empty()){
            if(!compare(s.top(),A[i])){
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
