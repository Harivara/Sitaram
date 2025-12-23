https://leetcode.com/contest/weekly-contest-402/problems/count-pairs-that-form-a-complete-day-ii/

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> freq(24, 0);  // frequency of each remainder mod 24
        for (int h : hours) {
            freq[h % 24]++;
        }

        long long count = 0;

        // Pairs that sum to 24 (i + j == 24)
        for (int i = 1; i < 12; i++) {
            count += freq[i] * freq[24 - i];
        }

        // Handle pairs where both remainders are 0 or 12 (since 0+0=0 mod 24, 12+12=24 mod 24)
        count += (freq[0] * (freq[0] - 1)) / 2;
        count += (freq[12] * (freq[12] - 1)) / 2;

        return count;
    }
};
