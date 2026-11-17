https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

class Solution {
  public:
    bool feasible(double mid, vector<int>& stations, int k) {
        int count = 0;
        for (int i = 0; i < stations.size() - 1; i++) {
            double diff = stations[i + 1] - stations[i];
            int needed = (int)(diff / mid);
            // If diff is an exact multiple of mid, one fewer station is needed
            if (diff == needed * mid) {
                needed--;
            }
            count += needed;
            if (count > k) {
                return false;
            }
        }
        return true;
    }

    double minMaxDist(vector<int>& stations, int k) {
        int n = stations.size();
        double low = 0.0;
        double high = stations[n - 1] - stations[0];

        while (high - low > 1e-6) {
            double mid = low + (high - low) / 2.0;
            if (feasible(mid, stations, k)) {
                high = mid;
            } else {
                low = mid; // Do not add 1 for double binary search
            }
        }

        return high;
    }
};




2. How feasible(mid) Works
Consider two adjacent existing stations at positions 10 and 20. The gap between them is diff = 10. 

Suppose we are testing mid = 3.0:
Divide the gap by mid:$$\frac{10}{3.0} = 3.33
 
\rightarrow \text{integer part } = 3$$

To make every sub-segment $\le 3.0$, 
we need 3 new stations (e.g., placed at 13, 16, 19), splitting the gap of 10 into segments of 3, 3, 3,1.

Edge case — Exact multiples:
Suppose diff = 10 and mid = 5.0:$$\frac{10}{5.0} = 2$$diff / mid gives 2 segments, 

which only requires 2 - 1 = 1 new station (placed at 15, creating two segments of 5.0). 
That's why we subtract 1 when diff == needed * mid.

Sum across all gaps:
We add up needed for every adjacent pair (stations[i], stations[i+1]). 
If the total exceeds k, mid is too small (return false). Otherwise, mid works (return true).