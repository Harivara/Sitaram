https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=problem-list-v2&envId=binary-tree

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
    int postindex=0;
TreeNode* conTree(vector<int>&in, vector<int>&post,int is,int ie){
    if(is>ie){
        return NULL;
    }
    TreeNode *root=new TreeNode(post[postindex++]);
    int index;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->val){
            index=i;
            break;
        }
    }
    root->right=conTree(in,post,index+1,ie);
    root->left=conTree(in,post,is,index-1);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        return conTree(inorder,postorder,0,postorder.size()-1);
    }
};