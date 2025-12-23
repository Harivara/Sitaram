https://leetcode.com/problems/recover-binary-search-tree/submissions/1823481642/?envType=problem-list-v2&envId=binary-tree

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
private:
    TreeNode *prev = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first)
                first = prev;
            second = root;
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};


consider a sorted array [1,2,5,3,7]
int first=-1,prev=-1,second=-1
for(i->n){
    if(arr[i]<prev){   // condition wrong
        if(first==-1){
            first=prev
            second=arr[i]
        }
    }
    prev=arr[i]
}