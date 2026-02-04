class Solution {
public:
    bool feasible(vector<int>& arr, int mid, int k) {
        int pages = 0;
        int students = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (pages + arr[i] > mid) {
                students++;
                pages = arr[i];
            } else {
                pages += arr[i];
            }
        }
        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;

        int low = 0, high = 0;
        for (int x : arr) {
            low = max(low, x);
            high += x;
        }

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (feasible(arr, mid, k)) {
                high = mid;     // minimize maximum
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
