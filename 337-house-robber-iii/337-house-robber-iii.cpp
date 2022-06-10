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
    int f(TreeNode* root,bool isPrev,unordered_map<TreeNode*,vector<int>>&dp)
    {
        if(!root)return 0;
        int mx=0;
        if(dp.find(root)==dp.end())dp[root]={-1,-1};
        if(dp[root][isPrev]!=-1)return dp[root][isPrev];
        if(isPrev==0)
        {
            
            mx=max(mx,root->val+f(root->left,1,dp)+f(root->right,1,dp));
        }
            int val=0;
            val+=f(root->left,0,dp);
            val+=f(root->right,0,dp);
            mx=max(mx,val);
        return dp[root][isPrev]=mx;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,vector<int>>dp;
        
        return f(root,0,dp);
    }
};