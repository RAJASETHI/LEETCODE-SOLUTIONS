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
    int f(TreeNode* root)
    {
        if(!root)return 0;
        int r=f(root->right);
        int l=f(root->left);
        if(l!=1)root->left=NULL;
        if(r!=1)root->right=NULL;
        return max({root->val,l,r});
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return root;
        int val=f(root);
        if(val!=1)return NULL;
        return root;
        
    }
};