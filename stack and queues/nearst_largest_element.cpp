// int Solution::maxSpecialProduct(vector<int> &A) {
//     int n = A.size();
//     vector<long long> left(n, 0), right(n, 0);
//     stack<int> s;

//     // Compute Left Special Value for each index
//     for (int i = 0; i < n; i++) {
//         while (!s.empty() && A[s.top()] <= A[i]) {
//             s.pop();
//         }
//         if (!s.empty()) {
//             left[i] = s.top();
//         }
//         s.push(i);
//     }

//     // Clear stack for right computation
//     while (!s.empty()) s.pop();

//     // Compute Right Special Value for each index
//     for (int i = n - 1; i >= 0; i--) {
//         while (!s.empty() && A[s.top()] <=A[i]) {
//             s.pop();
//         }
//         if (!s.empty()) {
//             right[i] = s.top();
//         }
//         s.push(i);
//     }

//     // Compute max special product
//     long long maxProduct = 0;
//     for (int i = 0; i < n; i++) {
//         maxProduct = max(maxProduct, left[i] * right[i]);
//     }

//     return (int)(maxProduct % 1000000007);
// }
