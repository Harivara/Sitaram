class Solution {
  public:

    int height(Node* root, int &diam) {
        if (root == NULL) {
            return 0;
        }

        int lh = height(root->left, diam);
        int rh = height(root->right, diam);

        diam = max(diam, lh + rh + 1);

        return 1 + max(lh, rh);
    }

    int diameter(Node* root) {
        int diam = 0;
        height(root, diam);
        return diam;
    }
};