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
    bool find(TreeNode* root,TreeNode* curr,int target)
    {
        if(root==NULL)return false;
        if(root->val==target && root!=curr)return true;
        else if(root->val>target)return find(root->left,curr,target);
        return find(root->right,curr,target);
    }
    bool f(TreeNode* curr,TreeNode* root,int k)
    {
        if(curr==NULL)return false;
        if(find(root,curr,k-curr->val)==true)return true;
        return f(curr->left,root,k) || f(curr->right,root,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return f(root,root,k);
    }
};