// int Solution::largestRectangleArea(vector<int> &A) {
//     int n=A.size();
//     stack<int>st;
//     int max_area=INT_MIN;
//     int currheight=0;
//     for(int i=0;i<=n;i++){
//         currheight=(i==n)?0:A[i];
//         while(!st.empty() && currheight<A[st.top()]){
//             int height=A[st.top()];
//             st.pop();
            
//             int width;
//             if(st.empty()){
//                 width=i;
//             }
//             else{
//                 width=i-1-st.top();    // we do -1 for i as we donot consider i as width
//             }
//             max_area=max(height*width,max_area);
            
//         }
//             st.push(i);
//     }
//     return max_area;
// }


// int Solution::largestRectangleArea(vector<int> &arr) {

//     int n=arr.size();
//     int leftSmall[n],rightSmall[n];
//     stack<int>st;
     
//     // smaller element on left
//     for(int i=0;i<n;i++){
//         while(!st.empty() && arr[st.top()]>=arr[i]){
//             st.pop();
//         }
//         if(st.empty()){
//             leftSmall[i]=0;
//         }
//         else{
//             leftSmall[i]=st.top()+1;
//         }
//         st.push(i);
//     }

//  // removing all the elements in stack to re-use the same stack instead of creating another
//     while(!st.empty()) st.pop();
   
//     // smaller element on right
//     for(int i=n-1;i>=0;i--){
//         while(!st.empty() && arr[st.top()]>=arr[i]){
//             st.pop();
//         }
//         if(st.empty()){
//             rightSmall[i]=n-1;
//         }
//         else{
//             rightSmall[i]=st.top()-1;
//         }
//         st.push(i);
//     }
   
// // calculating maximum Area
//     int area=0;
//     int maxArea=INT_MIN;
//     for(int i=0;i<n;i++){
//         area=arr[i]*(rightSmall[i]-leftSmall[i]+1);
//         maxArea=max(maxArea,area);
//     }
//     return maxArea;

// }