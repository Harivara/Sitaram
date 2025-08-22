// https://leetcode.com/problems/minimum-time-to-activate-string/description/



// Index: 0 1 2 3 4 5 6
// Char: a * b * * c d
// Suppose after some time t, the stars are activated at indices 1, 3, and 4, so those positions are stars.

// This splits the string into continuous segments without stars:

// Segment 1: index 0 (a) — length 1

// Segment 2: index 2 (b) — length 1

// Segment 3: indices 5, 6 (c, d) — length 2

// Total invalid substrings = 1+1+3=5.

// The total substrings in the original string of length 7 are: 7×(7+1) =28
// Thus, valid substrings = 28−5=23.
// if(valid>=k) check for a smaller answer . else increase the search space.

class Solution {
public:

    bool isValid(string s, vector<int>& order, int k, int t) {
        for(int i = 0; i <= t; i++) {
            s[order[i]] = '*';
        }
        long long n = order.size(), idxStar = -1;
        long long sum = 0;
        long long count=0;
        for (int i = 0; i < n; ++i) {
            if(s[i]!='*'){
                count++;
            }
            else{
                sum=sum+((count*(count+1))/2);
                count=0;
            }
        }
        if(count!=0){
            sum=sum+(count*(count+1))/2; 
        }
        long long total=n*(n+1)/2;
        return total-sum >= (long long)k;
    }
    
    int minTime(string s, vector<int>& order, int k) {
        int n = order.size(), left = 0, right = n-1;
        int ans=-1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(isValid(s, order, k, mid)) {
                // ans=mid;
                right = mid;
            } else {
                left = mid+1;
            }
        }
        if (isValid(s, order, k, left)) {
                return left;
            }
    return -1;   
     }
};

class Solution {
public:

    bool isValid(string s, vector<int>& order, int k, int t) {
        for(int i = 0; i <= t; i++) {
            s[order[i]] = '*';
        }
        int n = order.size(), idxStar = -1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                idxStar = i;
            }
            if (idxStar != -1) {
                sum += (long long)idxStar + 1;
            }
        }
        
        Find total no of substrings 
        return sum >= (long long)k;
    }
    
    int minTime(string s, vector<int>& order, int k) {
        int n = order.size(), left = 0, right = n-1, ans = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(isValid(s, order, k, mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};