// Input

// 6
// -1 -1 0 1 1 1
// Output

// 2

int countDistinctAbsoluteValues(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    int count = 0;

    while (left <= right) {

        int leftAbs = abs(arr[left]);
        int rightAbs = abs(arr[right]);

        if (leftAbs > rightAbs) {
            count++;

            while (left <= right && abs(arr[left]) == leftAbs) {
                left++;
            }
        }
        else if (leftAbs < rightAbs) {
            count++;

            while (left <= right && abs(arr[right]) == rightAbs) {
                right--;
            }
        }
        else {
            // Both sides represent the same absolute value
            count++;

            while (left <= right && abs(arr[left]) == leftAbs) {
                left++;
            }

            while (left <= right && abs(arr[right]) == rightAbs) {
                right--;
            }
        }
    }

    return count;
}