class Solution {
public:
    void merge(int low, int mid, int high,
               vector<pair<int,int>> &arr,
               vector<int> &res) {

        vector<pair<int,int>> temp;
        int i = low, j = mid + 1;

        while (i <= mid && j <= high) {
            if (arr[i].first <= arr[j].first) {
                // element from right goes first → no count added
                temp.push_back(arr[j]);
                j++;
            } else {
                // arr[i] > arr[j]
                // all remaining elements in right are smaller than arr[i]
                res[arr[i].second] += (high - j + 1);
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    void mergeSort(int low, int high,
                   vector<pair<int,int>> &arr,
                   vector<int> &res) {

        if (low >= high) return;

        int mid = low + (high - low) / 2;
        mergeSort(low, mid, arr, res);
        mergeSort(mid + 1, high, arr, res);
        merge(low, mid, high, arr, res);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(0, n - 1, arr, res);
        return res;
    }
};
