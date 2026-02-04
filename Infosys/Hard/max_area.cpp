class Solution {
  public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n ? 0 : heights[i]);

        while (!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    return maxArea;
}
int maxArea(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();

    int maxRect = largestRectangleArea(mat[0]);

    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 1)
                mat[i][j] += mat[i - 1][j];
            else
                mat[i][j] = 0;
        }
        maxRect = max(maxRect, largestRectangleArea(mat[i]));
    }
    return maxRect;
}

};