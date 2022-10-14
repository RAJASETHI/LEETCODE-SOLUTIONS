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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)return NULL;
        ListNode *slow=head,*prev=NULL,*fast=head;
        
        while(fast )
        {
            fast=fast->next;
            if(fast)fast=fast->next;
            if(fast==NULL || fast->next==NULL)
            {
                ListNode* tmp=slow->next;
                slow->next=tmp->next;
                tmp->next=NULL;
                return head;
            }
            else
            {
                prev=slow;
                slow=slow->next;
            }
        }
        return head;
    }
};