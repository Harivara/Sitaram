https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1


// Because if one train departs at 10:00 and another arrives at 10:00, the same platform can be reused (as per the usual GFG convention)
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n=arr.size();
        vector<int>freq(2361,0);
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            freq[dep[i]+1]--;
        }
        
        int count=0;
        int maxi=0;
        for(int i=0;i<=2360;i++){
            count+=freq[i];
            maxi=max(maxi,count);
        }
        
        return maxi;
    }
};


class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}


