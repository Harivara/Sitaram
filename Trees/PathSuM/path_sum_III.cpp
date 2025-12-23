https://leetcode.com/problems/path-sum-iii/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:
    int countFromNode(TreeNode* root, long long sum) {
        if (!root) return 0;

        int count = 0;
        if (root->val == sum) count++;

        count += countFromNode(root->left, sum - root->val);
        count += countFromNode(root->right, sum - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        return countFromNode(root, targetSum) 
             + pathSum(root->left, targetSum) 
             + pathSum(root->right, targetSum);
    }
};
