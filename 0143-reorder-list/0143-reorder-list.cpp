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
    ListNode* reverse(ListNode* temp){
        ListNode* curr=temp;
        ListNode* pre=NULL;
        while(curr){
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(!head) return;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode* m=slow->next;
       slow->next=NULL;
       ListNode* rev=reverse(m);
       ListNode* temp=head;
       while(rev){
        ListNode* next1=temp->next;
        ListNode* next2=rev->next;
        temp->next=rev;
        rev->next=next1;
        temp=next1;
        rev=next2;
       }
       return;
    }
};