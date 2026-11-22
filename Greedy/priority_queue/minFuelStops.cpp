// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/?utm_source=chatgpt.com


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        priority_queue<int>pq;
        int curr=startFuel;
        int i=0;
        int res=0;
        while(curr<target){
            while(i<n && curr>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            int dist=pq.top();
            pq.pop();
            curr=curr+dist;
            res++;
        }
        return res;
    }
}; 