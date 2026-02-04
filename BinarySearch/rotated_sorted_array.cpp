#include <bits/stdc++.h>
using namespace std;

int searchRotated(vector<int>& arr, int target) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        // Handle duplicates case
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // If left half is sorted
        if (arr[low] <= arr[mid]) {

            if (target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {

            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;   // element not found
}

int main() {

    vector<int> arr = {2,5,6,0,0,1,2};

    int target = 0;

    int index = searchRotated(arr, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
