// int Solution::trap(const vector<int> &A) {
//     int n = A.size();
//     if (n == 0) return 0;

//     vector<int> left(n), right(n);
//     int water = 0;

//     // Fill left max
//     left[0] = A[0];
//     for (int i = 1; i < n; i++) {
//         left[i] = max(left[i - 1], A[i]);
//     }

//     // Fill right max
//     right[n - 1] = A[n - 1];
//     for (int i = n - 2; i >= 0; i--) {
//         right[i] = max(right[i + 1], A[i]);
//     }

//     // Calculate trapped water
//     for (int i = 0; i < n; i++) {
//         water += min(left[i], right[i]) - A[i];
//     }

//     return water;
// }

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int left=0,right=n-1,left_max=0,right_max=0;
    int water=0;
    while(left<=right){
        if(A[left]<=A[right]){
            if(A[left]>=left_max){
                left_max=A[left];
            }
            else{
                water=water+left_max-A[left];
            }
        left++;
        }
        else{
            if(A[right]>=right_max){
                right_max=A[right];
            }
            else{
                water=water+right_max-A[right];
            }
            right--;
        }
    }
    return water;
}
