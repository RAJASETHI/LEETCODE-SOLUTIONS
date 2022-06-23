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
    bool f(TreeNode* root,int &h)
    {
        if(!root)return true;
        int l=0,r=0;
        bool ans=f(root->left,l) && f(root->right,r);
        if(abs(r-l)>1)ans=false;
        h=max(r,l)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        int h=0;
        return f(root,h);
    }
};