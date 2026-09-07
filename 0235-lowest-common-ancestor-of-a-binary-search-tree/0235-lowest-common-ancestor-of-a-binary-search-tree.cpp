/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mini=min(p->val,q->val);
        int maxi=max(p->val,q->val);
        if(root && root->val <= maxi && root->val >= mini) return root;
        else if(root && root->val > mini) return lowestCommonAncestor(root->left,p,q);
        else if(root && root->val < mini) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};