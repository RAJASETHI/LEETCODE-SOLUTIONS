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
    TreeNode* f(int &idx,string s,int depth,int &curr)
    {
        if(idx==s.size())return NULL;
        int cnt=0;
        while(idx<s.size() && s[idx]=='-')curr++,idx++;
        
        if(depth==curr)
        {
            string tmp;
            while(idx<s.size() && s[idx]>=48 && s[idx]<=57)tmp+=s[idx++];
            TreeNode* root=new TreeNode(stoi(tmp));
            curr=0;
            root->left=f(idx,s,depth+1,curr);
            root->right=f(idx,s,depth+1,curr);
            return root;
        }
        return NULL;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0,curr=0;
        return f(i,traversal,0,curr);
        
    }
};