class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited,
             set<int>& grid) {
        visited[node] = 1;
        grid.insert(node);
        for (auto& v : graph[node]) {
            if (!visited[v]) {
                dfs(v, graph, visited, grid);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> graph(c + 1);
        for (auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<set<int>> powergrid;
        vector<int> visited(c + 1, 0);
        set<int> grid;

        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, grid);
                powergrid.push_back(grid);
                grid.clear();
            }
        }

        vector<int> online(c + 1, 1); // all nodes initially online
        vector<int> ans;

        for (auto& q : queries) {
            int type = q[0], node = q[1];

            if (type == 2) {
                online[node] = 0; // mark node offline
            } else if (type == 1) {
                if (online[node]) {
                    ans.push_back(node);
                } else {
                    bool found = false;
                    for (auto& comp : powergrid) {
                        if (comp.count(node)) {
                            for (auto& v : comp) {
                                if (online[v]) {
                                    ans.push_back(v);
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                ans.push_back(-1);
                            }
                            break; // once the component is found, exit
                        }
                    }
                }
            }
        }

        return ans;
    }
};
©leetcode


class Solution {
public:
        unordered_map<int, set<int> > mp;
    void dfs(int node,vector<vector<int>> &adj, vector<int> &visited, int id,vector<int> &ids){
        visited[node] = 1;
        ids[node] = id;
        mp[id].insert(node);
        for(auto nodes : adj[node]){
            if(!visited[nodes]){
                dfs(nodes,adj,visited,id,ids);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> visited(c+1,0);

        vector<vector<int>> adj(c+1);

        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int> ids(c+1);


        for(int i=1;i<=c;i++){
            if(!visited[i]){
                dfs(i,adj,visited,i,ids);
            }
        }

        // for(int i=1;i<=c;i++){
        //     cout<<ids[i]<<" ";
        // }
        // cout<<endl;

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0] == 1){


                int node = queries[i][1];

                int check_id = ids[node];
                if(mp[check_id].count(node)){
                    ans.push_back(node);
                }
                else if(mp[check_id].size() != 0){
                    ans.push_back(*(mp[check_id].begin()));
                }
                else ans.push_back(-1);
            }
            else{

                int node=  queries[i][1];

                int check_id = ids[node];

                if(mp[check_id].count(node)){
                    mp[check_id].erase(node);
                }
            }
        }

        return ans;

    }
};

class UnionFind { // usual UnionFind class
    vector<int> root, rank;
public:
    UnionFind(int N) : root(N+1), rank(N+1){// for 1-indexed 
        rank.assign(N+1, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {//Path compression
        return (x == root[x])?x:root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {//Union by rank
        x= Find(x), y= Find(y);
        if (x==y)
            return 0;
        if (rank[x] > rank[y])
            swap(x, y);
        root[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
        return 1;
    }
};

class Solution {
public:
    static vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind G(c);
        for(auto& e: connections){
            G.Union(e[0], e[1]);
        }
        vector<set<int>> comp(c+1);
        for(int i=1; i<=c; i++){
            comp[G.Find(i)].insert(i);
        }
        vector<int> ans;
        for(auto& q: queries){
            const int t=q[0], x=q[1], rx=G.Find(x);
            auto& C=comp[rx];
            if (t==2)
                C.erase(x);
            else{
                if (C.empty()) ans.push_back(-1);
                else if (C.count(x)) ans.push_back(x);
                else ans.push_back(*C.begin());
            }

        }
        return ans;
    }
};