https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=problem-list-v2&envId=shortest-path


//This can be achieved with normal BFS too

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        pq.push({0,{src,0}});
        dist[src][0]=0;
       
        while(!pq.empty()){
            int currnode=pq.top().second.first;
            int currprice=pq.top().first;
            int stops=pq.top().second.second;
            pq.pop();

            if(stops==k+1){
                continue;
            }
            if(currprice>dist[currnode][stops]){
                continue;
            }
            

            for(auto &[nextnode,price]:adj[currnode]){
                int nextprice=price+currprice;
                if(nextprice<dist[nextnode][stops+1]){
                    pq.push({nextprice,{nextnode,stops+1}});
                    dist[nextnode][stops+1]=nextprice;
                    
                }
            }
            
        }

    
        int mini=INT_MAX;
        for(int i=0;i<=k+1;i++){
            mini=min(dist[dst][i],mini);
        }
        return mini==INT_MAX?-1:mini;
    }
};