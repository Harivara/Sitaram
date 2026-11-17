https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=arr.size();
        if(n==0 || n==1){
            return 0;
        }
       
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int cost=0;
        while(pq.size()!=1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            cost+=a+b;
            pq.push(a+b);
        }
        
        return cost;
    }
};