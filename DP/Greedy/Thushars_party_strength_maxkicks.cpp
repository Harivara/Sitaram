https://www.interviewbit.com/problems/tushars-birthday-bombs/

vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
   
    int min_ind = 0;
   
    for(int i=0;i<n;i++){
        if(B[i] < B[min_ind]){
            min_ind = i;
        }
    }
   
    int max_kicks = A/B[min_ind];
   
    vector<int>ans;
   
    while(max_kicks > 0){
        for(int i=0;i<n;i++){
            if(B[i] + B[min_ind] * (max_kicks-1) <= A){
                ans.push_back(i);
                max_kicks--;
                A -= B[i];
                break;
            }
        }
    }
   
    return ans;
   
}