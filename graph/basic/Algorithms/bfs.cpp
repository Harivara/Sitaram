#include<bits/stdc++.h>
using namespace std;

void bfs(int node,vector<vector<int>>&graph){
    int n=graph.size();
    queue<int>q;
    vector<int>visited(n,0);
    
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            q.push(i);
        }
        while (!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int v:graph[node]){
                if(visited[v]==0){
                    q.push(v);
                }
            }
        }
        
    }
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // remove this if graph is directed
    }

    cout << "BFS traversal: ";
    bfs(0, graph); // start BFS from node 0
    cout << endl;

    return 0;
}
