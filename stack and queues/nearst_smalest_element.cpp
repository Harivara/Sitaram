// vector<int> Solution::prevSmaller(vector<int> &A) {
//     stack<int>s;
//     s.push(A[0]);
//     vector<int>v;
//     v.push_back(-1);
//     for(int i=1;i<A.size();i++){
//         while(s.empty()==false && s.top()>=A[i]){
//             s.pop();
//         }
//         if(s.empty()==true){
//             v.push_back(-1);
//         }
//         else{
//             v.push_back(s.top());
//         }
//         s.push(A[i]);
//     }
//     return v;
// }
