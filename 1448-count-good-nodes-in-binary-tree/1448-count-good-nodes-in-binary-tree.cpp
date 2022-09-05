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
    int res=0;
    void f(TreeNode* root,int mx)
    {
        if(!root)return;
        mx=max(mx,root->val);
        if(root->val>=mx)res++;
        f(root->left,mx);
        f(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        res=0;
        f(root,INT_MIN);
        return res;
    }
};