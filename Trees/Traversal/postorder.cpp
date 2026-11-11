vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* node = root;

    while (node != NULL || !st.empty()) {
        // Go as far left as possible
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }

        // Process the node
        node = st.top();
        st.pop();
        ans.push_back(node->val);

        // Move to the right subtree
        node = node->right;
    }

    return ans;
}