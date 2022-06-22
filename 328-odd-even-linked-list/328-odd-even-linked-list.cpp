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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*l1=NULL,*l2=NULL;
        ListNode* h1=NULL,*h2=NULL;
        while(head)
        {
            if(l1)
            {
                l1->next=head;
                l1=l1->next;
            }
            else {l1=head;h1=l1;}
            head=head->next;
            if(head)
            {
                if(l2)
                {
                    l2->next=head;
                    l2=l2->next;
                }
                else{ l2=head;h2=l2;}
                head=head->next;
            }
        }
        if(l1)l1->next=h2;
        if(l2)l2->next=NULL;
        return (h1?h1:h2);
    }
};