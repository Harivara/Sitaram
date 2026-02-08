class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0, candidate = 0;

        // Phase 1: find candidate
        for (int x : arr) {
            if (count == 0) {
                candidate = x;
                count = 1;
            } else if (x == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Phase 2: verify candidate
        count = 0;
        for (int x : arr) {
            if (x == candidate)
                count++;
        }

        if (count > arr.size() / 2)
            return candidate;

        return -1;  // no majority element
    }
};
