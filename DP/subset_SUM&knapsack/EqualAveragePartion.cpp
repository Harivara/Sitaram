https://www.interviewbit.com/problems/equal-average-partition/

bool findSubset(int ind, int num, int target, vector<int>& subset, const vector<int>& A, vector<vector<vector<bool>>>& dp,int n) {
    if (num == 0 && target == 0) return true;
    if (ind > n || num < 0 || target < 0) return false;

    if (dp[ind][num][target]) return false;
    
    // Try including current
    subset.push_back(A[ind]);
    if (findSubset(ind + 1, num - 1, target - A[ind], subset, A, dp,n)) return true;
    subset.pop_back();

    // Try excluding current
    if (findSubset(ind + 1, num, target, subset, A, dp,n)) return true;


    // Memoize failed state
    dp[ind][num][target] = true;
    return false;
}

vector<vector<int>> Solution::avgset(vector<int>& A) {
    int n = A.size();
    int totalSum = 0;
    for(int i=0;i<n;i++){
        totalSum+=A[i];
    }
    sort(A.begin(), A.end()); // to ensure lexicographically smallest result

    for (int size = 1; size < n; ++size) {
        if ((totalSum * size) % n != 0) continue;

        int target = (totalSum * size) / n;
        vector<int> subset;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(size + 1, vector<bool>(target + 1, false)));

        if (findSubset(0, size, target, subset, A, dp,n-1)) {
            vector<int> remaining;
            multiset<int> s(A.begin(), A.end());
            for (int x : subset) s.erase(s.find(x));
            for (int x : s) remaining.push_back(x);
            

            return {subset, remaining};
        }
    }

    return {};
}

S1/n1=S2/n2;
S1/n1=(total-S1)/(n-n1);
(n-n1)S1=total*n1-S1n1;
n*S1=total*n1;

S1=(total*n1)/n;   --->> first condition (total*size)%n!=0
                    size of n1 can be 1-->n-1;
