https://www.interviewbit.com/problems/sliding-window-maximum/                                         
                                             // USING QUEUE

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    queue<int>qe;
    int maxiq=INT_MIN;
    vector<int>res;
    for(int i=0;i<B;i++){
        maxiq=max(maxiq,A[i]);
        qe.push(A[i]);
    }
    res.push_back(maxiq);
    for(int i=B;i<A.size();i++){
        if(A[i]>=maxiq){
            maxiq=A[i];
            qe.pop();
            qe.push(A[i]);
            res.push_back(maxiq);

        }
        else{
            if(qe.front()==maxiq){
                maxiq=INT_MIN;
                qe.pop();
                qe.push(A[i]);
                for(int j=0;j<qe.size();j++){
                    maxiq=max(maxiq,qe.front());
                    qe.push(qe.front());
                    qe.pop();
                }
                res.push_back(maxiq);
            }
            else{
                res.push_back(maxiq);
                qe.push(A[i]);
                qe.pop();
                
            }
        }
    }
    return res;
}

                                                     USING DEQUEUE
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < A.size(); i++) {
        // Remove elements out of this window
        if (!dq.empty() && dq.front() == i - B) {
            dq.pop_front();
        }

        // Remove all elements smaller than current, from the back
        while (!dq.empty() && A[dq.back()] < A[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Start adding results from when we have a full window
        if (i >= B - 1) {
            res.push_back(A[dq.front()]);
        }
    }

    return res;
}
