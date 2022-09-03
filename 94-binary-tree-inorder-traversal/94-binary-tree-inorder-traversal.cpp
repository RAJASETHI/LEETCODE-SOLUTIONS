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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>q;
        vector<int>res;
        while(root || q.size())
        {
            if(root)
            {
                q.push(root);
                root=root->left;
            }
            else
            {
                root=q.top();
                res.push_back(root->val);
                q.pop();
                root=root->right;
            }
        }
        return res;
    }
};