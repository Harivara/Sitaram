// 🔍 Line-by-line Explanation:
// 🔁 for (auto& [nei, wt] : graph[node])
// For every outgoing edge from node to its neighbor nei, with weight wt.

// 🚫 if (!online[nei] && nei != n - 1) continue;
// Skip the neighbor if it's offline, except for the final node (n - 1), which is always allowed (as per problem constraints).

// This ensures that all intermediate nodes are online.

// 🚫 if (wt < minEdge) continue;
// We're binary searching on minimum edge weight allowed in the path.

// So if the current edge weight wt is less than the target minEdge, we skip it.

// ✅ if (currCost + wt < cost[nei])
// This is a standard cost optimization check:

// We’ve already recorded the best-known cost to reach nei as cost[nei]

// If we found a cheaper way to reach nei via node → nei, update it.

// This helps us prune costly paths and avoid unnecessary recursion.

// 📞 dfs(nei, currCost + wt, minEdge, cost, visited)
// Recurse into the neighbor node, continuing the DFS with:

// Updated cost (currCost + wt)

// Same minimum edge (minEdge)

// cost table to track best costs

// visited array to avoid cycles

// 🛑 if (...) return true;
// If we reach n - 1 via this path, return true early to indicate that a valid path exists for this minEdge value.



// https://leetcode.com/problems/network-recovery-pathways/description/





// DFS SOLUTION GIVES TLE FOR LARGER NO OF EDGES BFS(Topological sort) WORKS
class Solution {
public:
        vector<vector<pair<int,int>>>graph;
        vector<bool>online;
        long long k;
        int n;

// bool dfs(int node,long long currcost,vector<long long>&cost,vector<bool>&visited, int mid){
//     if(currcost>k){
//         return false;
//     }
//     if(node==n-1){
//         return true;
//     }
//     if(visited[node]){
//         return false;
//     }

//     visited[node]=true;
//     for(auto &[nei,wt]:graph[node]){
//         if(!online[nei] && nei!=n-1 ){
//             continue;
//         }
//         if(wt<mid){
//             continue;
//         }
//         if(currcost+wt<cost[nei]){
//             cost[nei]=wt+currcost;
//             if(dfs(nei,currcost+wt,cost,visited,mid)){
//                 return true;
//             }
//         }
//     }
//     visited[node]=false;
//     return false;
// }
    
    
bool CanReachWithMinEdge(int mid){
    vector<bool>visited(n,false);
    vector<long long>cost(n,LLONG_MAX);
    cost[0]=0;
    // return dfs(0,0,cost,visited,mid);
    vector<vector<pair<int,int>>>filtered_graph(n);
    vector<int>indegree(n,0);
    for(int u=0;u<n;u++){
    for(auto &[nei,w]:graph[u]){
        if(w>=mid && (online[nei] || nei==n-1)){
            filtered_graph[u].push_back({nei,w});
            indegree[nei]++;
        }
    }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &[nei,w]:filtered_graph[u]){
                if(cost[u]!=LLONG_MAX && cost[u]+w<cost[nei]){
                    cost[nei]=cost[u]+w;
                }
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
            
        }
    return cost[n-1]<=k;
        
}
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>&_online, long long _k) {
        k=_k;
        online=_online;
        n=online.size();
        graph.resize(n);

        int left=0;
        int right=0;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            graph[u].push_back({v,w});
            right=max(right,w);
        }
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(CanReachWithMinEdge(mid)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
        
    }
};©leetcode