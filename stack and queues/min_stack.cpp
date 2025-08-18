https://www.interviewbit.com/problems/min-stack/

stack<int>s;
int minele;

MinStack::MinStack() {
    s = stack<int>();
}

void MinStack::push(int x) {
    if(s.size()==0){ 
        s.push(x);
        minele=x;
        return;
    }
    if(x>=minele)
        s.push(x);
    else
    {
        s.push(2*x-minele);
        minele=x;
    }
}

void MinStack::pop() {
    if(s.size()==0) return;
    if(s.top()<minele)
    {
        minele=(2*minele)-s.top();
    }
    s.pop();
}

int MinStack::top() {
    if(s.size()==0) return -1;
    if(s.top()<minele) return minele;
    else 
    return s.top();
}

int MinStack::getMin() {
    if(s.size()==0) return -1;
    return minele;
}