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
    ListNode* reverse(ListNode* head){
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rev=reverse(head);
        if(n==1){
            return reverse(rev->next);
        }
        ListNode* p=rev;
        ListNode* a=NULL;
        while(rev && n-1){
            a=rev;
            rev=rev->next;
            n--;
        }
        a->next=rev->next;
        ListNode* temp=reverse(p);
        return temp;
    }
};