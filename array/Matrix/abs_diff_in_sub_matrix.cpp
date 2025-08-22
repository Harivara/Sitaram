https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res;
        for(int i=0;i<=n-k;i++){
            vector<int>ans;
            for(int j=0;j<=m-k;j++){
                set<int>s;
                int mini=INT_MAX;
                for(int p=i;p<k+i;p++){
                    for(int q=j;q<k+j;q++){
                        s.insert(grid[p][q]);
                    }
                }
                if(s.size()==1){
                    ans.push_back(0);
                    continue;
                }
                vector<int>order;
                for(auto x:s){
                    order.push_back(x);
                }
                for(int a=0;a<order.size()-1;a++){
                    mini=min(mini,abs(order[a]-order[a+1]));
                }
                ans.push_back(mini);

            }
            res.push_back(ans);
        }
        return res;
    }
};