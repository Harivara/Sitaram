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


// This works when the search space looks like:

// F F F F T T T T
//         ^
//       answer

// where the condition changes from false to true.

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// What if you need the maximum feasible value?

// For problems like Maximum Safeness Factor, the pattern is:

// T T T T F F F
//         ^
//       answer

// The last true is the answer.

// Your template won't work directly because it is designed to find the first true.

// Option 1 (Recommended): Reverse the condition

// Search for the first false.

// while(left < right){
//     int mid = left + (right-left+1)/2;

//     if(feasible(mid))
//         left = mid;
//     else
//         right = mid - 1;
// }

// return left;

// Notice:

// mid is biased to the right with +1.
// When feasible(mid) is true, move left = mid.
// Otherwise move right = mid - 1.

// This finds the last true.






// Option 2: Convert to "first true"

// Suppose you want the maximum feasible value.

// Instead of

// T T T T F F

// think of the condition

// !feasible(mid)

// which becomes

// F F F F T T

// Now your favorite template works:

// while(left < right){
//     int mid = left + (right-left)/2;

//     if(!feasible(mid))
//         right = mid;
//     else
//         left = mid + 1;
// }

// return left - 1;