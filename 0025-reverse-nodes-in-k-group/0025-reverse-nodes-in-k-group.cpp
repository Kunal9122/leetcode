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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*>st;
        ListNode* temp1=new ListNode(0);
        ListNode* temp=temp1;
        while(head){
            st.push(head);
            head=head->next;
            if(st.size()==k){
                while(!st.empty()){
                    temp1->next=st.top();
                    st.pop();
                    temp1=temp1->next;
                }
                temp1->next=NULL;
            }
        }
         stack<ListNode*>st1;
         while(!st.empty()){
            st1.push(st.top());
            st.pop();
         }
         while(!st1.empty()){
            temp1->next=st1.top();
            st1.pop();
            temp1=temp1->next;
         }
         temp1->next=NULL;
        return temp->next;
    }
};