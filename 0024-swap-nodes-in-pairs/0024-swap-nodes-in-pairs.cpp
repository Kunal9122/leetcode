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
    ListNode* swapPairs(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        ListNode* temp1=new ListNode(0);
        head=temp1;
        while(temp){
            st.push(temp);
            temp=temp->next;
              if(st.size()==2){
                ListNode* a=st.top();
                st.pop();
                ListNode* b=st.top();
                st.pop();
                temp1->next=a;
                temp1=temp1->next;
                temp1->next=b;
                temp1=temp1->next;
                temp1->next = NULL; 
            }
        }
        if(!st.empty()){
            temp1->next=st.top();
            st.pop();
        }
        return head->next;
    }
};