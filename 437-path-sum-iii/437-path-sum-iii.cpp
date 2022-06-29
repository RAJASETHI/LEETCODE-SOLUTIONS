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
    int f(TreeNode* root,int target,long long curr)
    {
        if(!root)return 0;
        curr+=root->val;
        return (curr==target)+f(root->left,target,curr)+f(root->right,target,curr);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        return (f(root,targetSum,0)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum));
    }
};