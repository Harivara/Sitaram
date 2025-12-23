https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=problem-list-v2&envId=binary-tree  


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
int preindex=0;
TreeNode* contree(vector<int>&pre, vector<int>&in,int is,int ie){
if(is>ie){
    return NULL;
}
    TreeNode* root=new TreeNode(pre[preindex++]);
    int index;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->val){
            index=i;
            break;
        }
    }
    root->left=contree(pre,in,is,index-1);
    root->right=contree(pre,in,index+1,ie);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return contree(preorder,inorder,0,inorder.size()-1);
    }
};