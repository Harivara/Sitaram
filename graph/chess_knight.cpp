int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int drow[8]={-2,-1,1,2,2,1,-1,-2};
    int dcol[8]={1,2,2,1,-1,-2,-2,-1};
    queue<pair<pair<int,int>,int>>q;
    q.push({{C,D},0});
    vector<vector<int>>vis(A+1,vector<int>(B+1,0));
    vis[C][D]=1;
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps=q.front().second;
        // vis[r][c]=1;
        q.pop();
        if(r==E && c==F){
            return steps;
        }
        
        for(int i=0;i<8;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
        
        if(nrow>0 && nrow<=A && ncol>0 && ncol<=B && vis[nrow][ncol]==0){
            vis[nrow][ncol]=1;
            q.push({{nrow,ncol},steps+1});
        }
        }
    }
    return -1;
}