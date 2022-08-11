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
    #define ll long long
    bool isValidBST(TreeNode* root,ll mx=INT_MAX,ll mn=INT_MIN) {
        if(!root)return true;
//         if(mx<mn)return false;
//         if(root->val==INT_MAX)return (root->right==NULL && isValidBST(root->left,root->val-1,mn));
        
//         if(root->val==INT_MIN)return (root->left==NULL && isValidBST(root->right,mx,root->val+1));
        return (root->val>=mn && root->val<=mx) && isValidBST(root->left,(ll)root->val-1,mn) &&             isValidBST(root->right,mx,(ll)root->val+1);
    }
};