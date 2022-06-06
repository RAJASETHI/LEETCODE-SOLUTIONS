/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA,*t2=headB;
        int f1=0,f2=0;
        while(t1 && t2 && t1!=t2)
        {
            t1=t1->next;
            t2=t2->next;
            if(!t1 && !f1)
            {
                t1=headB;
                f1=1;
            }
            if(!t2 && !f2)
            {
                t2=headA;
                f2=1;
            }
        }
        if(t1==t2)return t1;
        return NULL;
    }
};