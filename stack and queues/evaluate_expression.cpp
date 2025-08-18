https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    stack<string>st;
    for(int i=0;i<A.size();i++){
        if(A[i]=="*"){
            int a=stoi(st.top());
            st.pop();
            int b=stoi(st.top());
            st.pop();
            st.push(to_string(a*b));
        }
       else if(A[i]=="/"){
            int a=stoi(st.top());
            st.pop();
            int b=stoi(st.top());
            st.pop();
            st.push(to_string(b/a));
        }
        else if(A[i]=="+"){
            int a=stoi(st.top());
            st.pop();
            int b=stoi(st.top());
            st.pop();
            st.push(to_string(a+b));
        }
        else if(A[i]=="-"){
            int a=stoi(st.top());
            st.pop();
            int b=stoi(st.top());
            st.pop();
            st.push(to_string(b-a));
        }
        else{
            st.push(A[i]);
        }
    }
    return stoi(st.top());
}
