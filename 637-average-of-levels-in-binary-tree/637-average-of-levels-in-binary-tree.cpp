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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        double sum=0,cnt=0;
        while(q.size())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node)
            {
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                sum+=node->val;
                cnt++;
            }
            else 
            {
                if(q.size())
                    q.push(NULL);
                res.push_back(1.0*sum/cnt);
                sum=cnt=0;
            }
        }
        return res;
    }
};