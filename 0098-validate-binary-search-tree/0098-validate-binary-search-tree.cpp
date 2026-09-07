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
    int mini(TreeNode* root){
        if(!root->left) return root->val;
        return mini(root->left);
    }
    int maxi(TreeNode* root){
        if(!root->right) return root->val;
        return maxi(root->right);
    }
    bool helper(TreeNode* root){
        if(!root) return true;
        if(root->right){
            int m=mini(root->right);
            if(root->val >= m) return false;
        }
        if(root->left){
            int l=maxi(root->left);
            if(root->val <= l) return false;
        }
        
        
        //if(root->left && root->left->val >= root->val) return false;
        //else if(root->right && root->right->val <= root->val) return false;
        return helper(root->left) && helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};