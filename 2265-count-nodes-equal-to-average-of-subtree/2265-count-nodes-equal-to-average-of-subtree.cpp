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
    vector<int> f(TreeNode* root)
    {
        if(!root)return {0,0};
        vector<int>left=f(root->left),right=f(root->right);
        int sum=left[0]+right[0]+root->val;
        int cnt=1+left[1]+right[1];
        // cout<<sum/cnt<<" "<<root->val<<"\n";
        if(int(sum/cnt)==root->val)res++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        res=0;
        int cnt=0;
        f(root);
        return res;
    }
};