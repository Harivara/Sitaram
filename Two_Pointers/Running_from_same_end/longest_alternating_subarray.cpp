int longestAltSubarray(int N, int* arr) {

    int left = 0;
    int ans = 1;
    int prev = 0;

    for (int right = 1; right < N; right++) {

        int curr = 0;

        if (arr[right] > arr[right-1])
            curr = 1;
        else if (arr[right] < arr[right-1])
            curr = -1;

        if (curr == 0) {
            left = right;
            prev = 0;
        }
        else {
            if (prev == curr) {
                left = right - 1;
            }

            prev = curr;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}