/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* dummy=new Node(78);
        Node* t1=dummy;
        while(temp){
            Node* a=new Node(temp->val);
            t1->next=a;
            t1=t1->next;
            temp=temp->next;
        }
        Node* b=dummy->next;
        Node* a=head;
        Node* c=dummy->next;
        Node* d=head;
        unordered_map<Node*,Node*>mp;
        while(c){
        mp[d]=c;
        c=c->next;
        d=d->next;
        }
        for(auto  x:mp){
            Node* o = x.first;
            Node* d = x.second;
            if(o->random!=NULL){
                Node* oRan=o->random;
                Node* dRan=mp[oRan];
                d->random=dRan;
            }
        }
        return b;
    }
};