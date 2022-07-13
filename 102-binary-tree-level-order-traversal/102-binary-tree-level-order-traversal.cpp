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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>level;
        while(q.size())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node)
            {
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            else
            {
                res.push_back(level);
                level={};
                if(q.size())q.push(NULL);
            }
        }
        return res;
    }
};