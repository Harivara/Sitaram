class Solution {
public:
    bool fun(Node* root, int b, vector<int>& v) {
        if (root == NULL) {
            return false;
        }

        v.push_back(root->key);

        if (root->key == b) {
            return true;
        }

        if (fun(root->left, b, v) ||
            fun(root->right, b, v)) {
            return true;
        }

        v.pop_back();
        return false;
    }

    vector<int> solve(Node* root, int b) {
        vector<int> v;
        fun(root, b, v);
        return v;
    }
};