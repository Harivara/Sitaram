https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({deadline[i],profit[i]});
        }
        
        sort(jobs.begin(),jobs.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<n;i++){
            if(jobs[i].first>pq.size()){
                pq.push(jobs[i].second);
            }
            else if(!pq.empty() && pq.top()<jobs[i].second){
                pq.pop();
                pq.push(jobs[i].second);
            }
        }
        
        int count=pq.size();
        int total=0;
        vector<int>v;
        while(!pq.empty()){
            total+=pq.top();
            pq.pop();
        }
        
        v.push_back(count);
        v.push_back(total);
        return v;
        
    }
};