https://leetcode.com/problems/validate-binary-search-tree/?envType=problem-list-v2&envId=binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode *root,long long st,long long end){
        if(root==NULL){
            return true;
        }
        if((long long)root->val>st && (long long)root->val<end){
            return (solve(root->left,st,(long long)root->val) && solve(root->right,(long long)root->val,end));
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};