// User function Template for C++

class Solution {
  public:
    long long smallestpositive(vector<long long> arr , int n) {
        // code here
            sort(arr.begin(), arr.end());

    long long res = 1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= res) {
            res += arr[i];
        } else {
            break;
        }
    }

    return res;
    }
};
