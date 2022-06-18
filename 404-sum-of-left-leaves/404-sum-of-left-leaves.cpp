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
    int f(TreeNode* root,int isleft)
    {
        if(!root)return 0;
        int sum=0;
        if(!(root->left) && !(root->right) && isleft)
        {
            sum+=root->val;
        }
        sum+=f(root->left,1);
        sum+=f(root->right,0);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int prev=0;
        return f(root,prev);
    }
};