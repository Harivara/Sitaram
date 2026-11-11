vector<vector<int>> verticalTraversal(Node* root) {
    vector<vector<int>> ans;

    if (root == NULL) {
        return ans;
    }

    // Map: column -> node values in BFS order
    map<int, vector<int>> mp;

    // Queue stores: {node, column}
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, col] = q.front();
        q.pop();

        mp[col].push_back(curr->data);

        if (curr->left != NULL) {
            q.push({curr->left, col - 1});
        }

        if (curr->right != NULL) {
            q.push({curr->right, col + 1});
        }
    }

    for (auto &it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}