/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)return {};
        queue<Node* >q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>res;
        vector<int>tmp;
        while(q.size())
        {
            Node* node=q.front();q.pop();
            if(node)
            {
                tmp.push_back(node->val);
                for(auto i:node->children)q.push(i);
            }
            else if(q.size())
            {
                res.push_back(tmp);
                tmp={};
                q.push(NULL);
            }
        }
        res.push_back(tmp);
        return res;
    }
};