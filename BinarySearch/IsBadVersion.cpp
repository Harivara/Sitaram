https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1,right=n;
        while(left<right){
            int mid=(left+right)/2;
            if(isBadVersion(mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};

// we have to find the minimum value of n which satisfies the funtion
// Decide return value. Is it return left or return left - 1? Remember this: 
// after exiting the while loop, left is the minimal k​ satisfying the condition function;