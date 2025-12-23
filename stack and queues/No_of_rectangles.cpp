https://leetcode.com/problems/count-submatrices-with-all-ones/description/?envType=daily-question&envId=2025-08-21

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int result = 0;

        for (int i = 0; i < n; i++) {
            // Step 1: update histogram heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }

            // Step 2: count submatrices using monotonic stack
            stack<int> st;
            vector<int> sum(m, 0); // sum[j] = submatrices ending at column j in this row

            for (int j = 0; j < m; j++) {
                while (!st.empty() && height[st.top()] >= height[j]) {
                    st.pop();
                }

                if (!st.empty()) {
                    // stack would not be empty when there zero in heights[0..j]
                    int prev = st.top(); // gives the index of height[j]=0
                    sum[j] = sum[prev] + height[j] * (j - prev);
                } else {
                    // stack would be empty when there is no zero in heights[0..j]
                    sum[j] = height[j] * (j + 1);
                }

                result += sum[j];
                st.push(j);
            }
        }
        return result;
    }
};
