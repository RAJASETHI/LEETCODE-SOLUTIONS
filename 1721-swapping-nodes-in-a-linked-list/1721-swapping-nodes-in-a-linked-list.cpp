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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr2=head,*ptr1=head;
        ListNode* x1,*x2;
        while(k>1)
        {
            ptr2=ptr2->next;
            k--;
        }
        x1=ptr2;
        while(ptr2->next)
        {
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        int data=ptr1->val;
        ptr1->val=x1->val;
        x1->val=data;
        return head;
    }
};