/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,int>mp;
        Node*tmp=head;
        int k=0;
        while(tmp)
        {
            mp[tmp]=k++;
            tmp=tmp->next;
        }
        vector<int>vis(k,-1);
        tmp=head;
        k=0;
        while(tmp)
        {
            if(tmp->random)
            vis[k++]=mp[tmp->random];
            else
                vis[k++]=-1;
            tmp=tmp->next;
        }
        tmp=head;
        Node* chead=new Node(-1);
        Node* itr=chead;
        k=0;
        unordered_map<int,Node*>getAddress;
        while(tmp)
        {
            itr->next=new Node(tmp->val);
            getAddress[k++]=itr->next;
            tmp=tmp->next;
            itr=itr->next;
        }
        chead=chead->next;
        itr=chead;
        k=0;
        while(itr)
        {
            if(vis[k]>=0)
            itr->random=getAddress[vis[k++]];
            else
                k++;
            itr=itr->next;
        }
        return chead;
    }
};