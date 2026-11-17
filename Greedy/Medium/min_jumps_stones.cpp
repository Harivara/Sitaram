https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A) {

    if(A.size()==1) return 0;

    int currReach=0,maxReach=0,jumps=0;

    for(int i=0;i<A.size();i++){
        maxReach=max(maxReach,A[i]+i);

        if(maxReach>=A.size()-1){
            return jumps+1;
        }

        if(i==currReach){
            if(maxReach==i){
                return -1;
            }
            else{
                jumps++;
                currReach=maxReach;
            }
        }
    }

    return -1;

}