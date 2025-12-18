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
    bool evaluateTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            if(root->val==1) return true;
            else return false;
        }
        bool left=false;
        bool right=false;
       if(root->left) left= evaluateTree(root->left);
       if(root->right) right=evaluateTree(root->right);
       bool res;
        if(root->val==2){
            if(left || right) res =true;
            else res =false;
        }
        else{
            if(left && right) res=true;
            else res=false;
        }
        return res;
    }
};