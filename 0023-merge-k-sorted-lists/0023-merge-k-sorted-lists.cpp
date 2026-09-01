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
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        int a=min(list1->val,list2->val);
        ListNode* n=NULL;
        if(list1->val==a){
            n=list1;
            list1=list1->next;
        } 
        else{
            n=list2;
            list2=list2->next;
        } 
        ListNode* head=n;
        while(list1 && list2){
            int b=min(list1->val,list2->val);
             if(list1->val==b){
                n->next=list1;
                n=n->next;
                list1=list1->next;
             }
             else{
                n->next=list2;
                n=n->next;
                list2=list2->next;
             }
        }
        while(list1){
            n->next=list1;
            n=n->next;
            list1=list1->next;
        }
        while(list2){
            n->next=list2;
            n=n->next;
            list2=list2->next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0) return NULL;
       while(lists.size()>1){
        ListNode* a=lists[lists.size()-1];
        lists.pop_back();
        ListNode* b=lists[lists.size()-1];
        lists.pop_back();
        ListNode* nn=mergeTwoLists(a,b);
        lists.push_back(nn);
       }
       return lists[0];
    }
};