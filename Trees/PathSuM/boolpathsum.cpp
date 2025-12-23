https://leetcode.com/problems/path-sum/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        
        if (!root->left && !root->right) {   // if(root->left!=NULL && root->right!=NULL && root->val==targetSum){
            return targetSum == root->val;   //    return true; }
                                             //     this does not check for root->val!=targetSum return false;
        }
        
        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);
        
        return left_sum || right_sum;
    }
};