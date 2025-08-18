https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> arr;
        for(int i = 0; i <= grid.size() - k; i++){
            vector<int> R;
            for(int j = 0; j <= grid[i].size() - k; j++){

                // SubMatrix
                set<int> num;
                int mini = INT_MAX;
                for(int I = i; I < k + i; I++){
                    for(int J = j; J < k + j; J++){
                       num.insert(grid[I][J]);
                    }
                }

                if(num.size() == 1){
                    R.push_back(0);
                    continue;
                }
                
                vector<int> J;
                for(auto M = num.begin(); M != num.end(); M++){
                    J.push_back(*M);
                }

                for(int G = 0; G < J.size() - 1; G++){
                    mini = min(mini,abs(J[G + 1] - J[G]));
                }

                R.push_back(mini);
            }

            arr.push_back(R);
        }

        return arr;
    }
};