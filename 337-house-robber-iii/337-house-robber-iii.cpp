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
private:
    int rob(TreeNode* root, int &rob_max, int &not_rob_max) {
        if (!root) return 0;
        int left_rob_max = 0, left_not_rob_max = 0, right_rob_max = 0, right_not_rob_max = 0;
        int left_max = rob(root->left, left_rob_max, left_not_rob_max);
        int right_max = rob(root->right, right_rob_max, right_not_rob_max);
        rob_max = root->val + left_not_rob_max + right_not_rob_max;
        not_rob_max = left_max + right_max;
        return max(rob_max, not_rob_max);
    }
public:
    int rob(TreeNode* root) {
        int rob_max = 0, not_rob_max = 0;
        return rob(root, rob_max, not_rob_max);
    }
};