/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l=NULL,*r=NULL;
        ListNode* lhead=NULL,*rhead=NULL;
        while(head)
        {
            if(head->val<x)
            {
                if(l==NULL)
                {
                    l=head;
                    lhead=l;
                }
                else
                {
                    l->next=head;
                    l=l->next;
                    
                }
                head=head->next;
            }
            else
            {
                if(r==NULL)
                {
                    r=head;
                    rhead=r;
                }
                else
                {
                    r->next=head;
                    r=r->next;
                }
                head=head->next;
            }
        }
        if(l)
            l->next=NULL;
        if(r)
            r->next=NULL;
        if(lhead)
        {
            l->next=rhead;
        }
        else lhead=rhead;
        return lhead;
    }
};