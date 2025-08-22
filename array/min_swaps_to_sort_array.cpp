// https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/

class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Create pairs of {sum_of_digits, original_index}
        vector<pair<int, int>> sumWithIndex;
        for (int i = 0; i < n; i++) {
            sumWithIndex.push_back({digitSum(nums[i]), i});
        }

        // Step 2: Sort the array based on sum of digits.
        sort(sumWithIndex.begin(), sumWithIndex.end(), [&](auto &a, auto &b) {
            if (a.first != b.first)
                return a.first < b.first;
            return nums[a.second] < nums[b.second]; // If sum is same, use original value
        });

        // Step 3: Count cycles to find minimum number of swaps
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // Already visited or already in correct place
            if (visited[i] || sumWithIndex[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = sumWithIndex[j].second;
                cycle_size++;
            }

            if (cycle_size > 1)
                swaps += (cycle_size - 1);
        }

        return swaps;
    }
};
©leetcode