// Right rotate → reverse all → reverse first d → reverse rest
// Left rotate = reverse first part → reverse second part → reverse all


class Solution {
  public:
  
    void reverse(vector<int>&arr, int low, int high){
        while(low<high){
            int temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
            low++;
            high--;
        }
    }
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
        
        
    }
};