https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/

class Solution {
public:
    int numberOfChild(int n, int k) {
        int multiple = n - 1;
        int q = k / multiple;
        int r = k % multiple;

        if (q % 2 == 0) {
            return r;                 // going forward
        } else {
            return multiple - r;      // going backward
        }
    }
};
©leetcode