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
    // NULL Node->return 2;
    // Leaf Node->return 0;
    // Parent of Leaf Node->return 1+res++;
    // return 2 if covered already without camera
    int res=0;
    int f(TreeNode* root)
    {
        if(!root)return 2;
        int left=f(root->left),right=f(root->right);
        if(left==0 || right==0)
        {
            res++;
            return 1;
        }
        return ((left==1 || right==1)?2:0);
    }
    int minCameraCover(TreeNode* root) {
        res=0;
        return (f(root)<1?1:0)+res;
    }
};