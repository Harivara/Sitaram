https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        long long int left=0,right=x+1;
        while(left<right){
            long long int mid=(left+right)/2;
             if(mid*mid>x){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left-1;  //`left` is the minimum k value, `k - 1` is the answer

    }
};

// First we need to search for minimal k satisfying condition k^2 > x, then k - 1 is the answer to the question.

// Notice that I set right = x + 1 instead of right = x to deal with special input cases like x = 0 and x = 1.