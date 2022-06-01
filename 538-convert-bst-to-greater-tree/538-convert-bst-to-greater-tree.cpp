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
    int f(TreeNode* root,int &sm)
    {
        if(!root)return 0;
        int r=f(root->right,sm);
        int tmp=sm+root->val;
        sm+=root->val;
        root->val=tmp;
        int l=f(root->left,sm);
        return l+root->val;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sm=0;
        f(root,sm);
        return root;
    }
};