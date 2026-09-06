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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* temp=root;
        TreeNode* temp1=root;
        while(root){
            if( root->val>val){
                temp1=root;
                root=root->left;
            }
            else if( root->val< val){
                temp1=root;
                root=root->right;
            }
        }
        TreeNode* nn=new TreeNode(val);
        if(!temp1->left && temp1->val > val) temp1->left=nn;
        else temp1->right=nn;
        return temp;
    }
};