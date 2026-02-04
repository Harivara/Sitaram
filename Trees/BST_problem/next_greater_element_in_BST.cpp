https://www.interviewbit.com/problems/next-greater-number-bst/

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* curr = A;
    TreeNode* successor = NULL;

    // Search for B, but even if not found, successor will store smallest > B
    while (curr) {
        if (curr->val > B) {
            successor = curr;  // this is a candidate for smallest > B
            curr = curr->left;
        } else if (curr->val < B) {
            curr = curr->right;
        } else {
            break; // found B
        }
    }

    // If B is found and has right subtree → return leftmost of right subtree
    if (curr && curr->right) {
        curr = curr->right;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    // Otherwise return stored successor (works for both found and not-found case)
    return successor;
}
