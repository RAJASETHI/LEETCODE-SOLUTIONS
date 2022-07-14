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
    TreeNode* f(int l,int r,int &idx,vector<int>& pre, vector<int>& in)
    {
        if(l>r || idx==pre.size())return NULL;
        if(l==r && ++idx)return new TreeNode(in[l]);
        int i=l;
        while(i<=r)
        {
            if(pre[idx]==in[i])break;
            i++;
        }
        if(i>r)return NULL;
        TreeNode* node=new TreeNode(pre[idx]);
        idx++;
        node->left=f(l,i-1,idx,pre,in);
        node->right=f(i+1,r,idx,pre,in);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return f(0,preorder.size()-1,idx,preorder,inorder);
    }
};