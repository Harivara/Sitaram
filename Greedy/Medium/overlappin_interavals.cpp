https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int start=arr[0][0];
            int end=arr[0][1];
            ans.push_back({start,end});
            int len=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]>end){
                ans.push_back({arr[i][0],arr[i][1]});
                end=arr[i][1];
                len++;
            }
            else{
                end=max(end,arr[i][1]);
                ans[len-1][1]=end;
            }
            
        }
        return ans;
    }
};