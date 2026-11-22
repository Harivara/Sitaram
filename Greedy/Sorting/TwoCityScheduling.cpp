https://leetcode.com/problems/two-city-scheduling/?utm_source=chatgpt.com



// Approach: Greedy (Sorting)
// For each person, calculate:

                                    // diff = costA-costB
                            

// - Negative difference → A is cheaper.
// - Positive difference → B is cheaper.
// - Sort by difference.
// - Send the first n people to A and the remaining n to B.

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](vector<int>&a,vector<int>&b){
            return (a[0]-a[1]<b[0]-b[1]);
        });

        int ans=0;
        for(int i=0;i<costs.size()/2;i++){
            ans+=costs[i][0];
        }
        for(int i=costs.size()/2;i<costs.size();i++){
            ans+=costs[i][1];
        }
        return ans;
    }
};