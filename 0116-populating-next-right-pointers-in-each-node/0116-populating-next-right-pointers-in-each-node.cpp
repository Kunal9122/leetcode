/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*>q;
        q.push(root);
        Node* temp=NULL;
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n-1;i++){
                Node* a=q.front();
                q.pop();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                Node* b=q.front();
                a->next=b;
            }
            Node* a=q.front();
            q.pop();
            if(a->left) q.push(a->left);
            if(a->right) q.push(a->right);
            a->next=NULL;
        }
        return root;
    }
};