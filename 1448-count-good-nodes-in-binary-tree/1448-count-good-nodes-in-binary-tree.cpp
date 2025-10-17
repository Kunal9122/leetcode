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
    int helper(TreeNode* root,int maxel){
        if(!root) return 0;
        int c=0;
        if(maxel<=root->val) c++;
        maxel=max(maxel,root->val);
        c+=helper(root->left,maxel);
        c+=helper(root->right,maxel);
        return c;
    }
    int goodNodes(TreeNode* root) {
        int c=helper(root,root->val);
        return c;
    }
};