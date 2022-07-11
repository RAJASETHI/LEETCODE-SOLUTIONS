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
    vector<int>res;
    void f(TreeNode* root,int &maxH,int h)
    {
        if(!root)return;
        if(maxH<h)
        {
            res.push_back(root->val);
            maxH=h;
        }
        f(root->right,maxH,h+1);
        f(root->left,maxH,h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        int maxH=-1;
        f(root,maxH,0);
        return res;
    }
};