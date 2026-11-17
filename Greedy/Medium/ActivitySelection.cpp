// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

// using longest Incresing Subsequence gives TLE


int activitySelection(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<vector<int>> arr(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        arr[i][0] = start[i];
        arr[i][1] = finish[i];
    }

    // Sort activities by finish time
    sort(arr.begin(), arr.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1];
         });

    int count = 1;
    int j = 0;

    for (int i = 1; i < n; i++) {

        // Select the activity if it starts after the last one finishes
        if (arr[i][0] > arr[j][1]) {
            count++;
            j = i;
        }
    }

    return count;
}

