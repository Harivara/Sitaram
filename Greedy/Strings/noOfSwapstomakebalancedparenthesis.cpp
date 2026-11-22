class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int maxImbalance = 0;

        for(char c : s) {
            if(c == '[') {
                balance++;
            }
            else {
                balance--;
            }

            maxImbalance = max(maxImbalance, -balance);
        }

        return (maxImbalance + 1) / 2;
    }
};