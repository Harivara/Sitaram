https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/submissions/1909295761/?envType=problem-list-v2&envId=graph

class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,int &count,vector<int>&vis){
    
    vis[node]=1;
    count++;
    for(auto &v:adj[node]){
        if(vis[v]==0){
            dfs(v,adj,count,vis);
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>v;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            int count=0;
            if(vis[i]==0){
                dfs(i,adj,count,vis);
            v.push_back(count);
            }
        }
        long long amount=0,sum=0;
        for(int i:v){
            cout<<i<<endl;
        }
        // for(int i=0;i<v.size()-1;i++){
        //     for(int j=i+1;j<v.size();j++){
        //         amount+=(long long)v[i]*(long long)v[j];
        //     }
        // }
        for (long long i : v) {
            amount += i * sum;
            sum += i;
        }
        return amount;
    }
};