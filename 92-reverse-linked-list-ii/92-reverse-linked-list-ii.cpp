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
    ListNode* f(ListNode* head,int cnt)
    {
        ListNode* hh=head;
        ListNode* prev=NULL;
        while(head && cnt)
        {
            ListNode* nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
            cnt--;
        }
        hh->next=head;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l==1)return f(head,r-l+1);
        int cnt=1;
        ListNode* t=head;
        while(cnt+1<l)
        {
            t=t->next;
            cnt++;
        }
        t->next=f(t->next,r-l+1);
        return head;
    }
};