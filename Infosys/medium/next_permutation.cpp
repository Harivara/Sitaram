class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
       
    int n = arr.size();
    int i = n - 2;

    // 1️⃣ find breakpoint
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // 2️⃣ if breakpoint exists
    if (i >= 0) {
        int j = n - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }
        swap(arr[i], arr[j]);
    }

    // 3️⃣ reverse suffix
    reverse(arr.begin() + i + 1, arr.end());
}

};