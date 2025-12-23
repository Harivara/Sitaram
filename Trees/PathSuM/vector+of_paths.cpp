https://leetcode.com/problems/path-sum-ii/submissions/998394474/?envType=problem-list-v2&envId=binary-tree

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
void path(TreeNode* root,int sum,vector<int>&v,vector<vector<int>>&ans){
    if(root==NULL){
        return;
    }
    v.push_back(root->val);
    if(root->val==sum && root->left==NULL && root->right==NULL){
        ans.push_back(v);
    }
   path(root->left,sum-root->val,v,ans);
   path(root->right,sum-root->val,v,ans);
   v.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        vector<vector<int>>ans;
        path(root,targetSum,v,ans);
        return ans;
    }
};