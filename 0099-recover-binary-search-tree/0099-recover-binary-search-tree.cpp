/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* midd=NULL;
    TreeNode* last=NULL;
    void preorder(TreeNode* root){
       if(!root) return;
        preorder(root->left);
        if(prev && prev->val > root->val){
            if(first==NULL){
                first=prev;
                midd=root;
            }
            else last=root;
        }
        prev=root;
        preorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        preorder(root);
        if(first && last) swap(first->val,last->val);
        else swap(first->val,midd->val);
        return;
    }
};