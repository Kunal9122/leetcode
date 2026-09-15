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
    int helper(TreeNode* root,int& maxsum){
        if(!root) return 0;
        int ls=max(0,helper(root->left,maxsum));
        int rs=max(0,helper(root->right,maxsum));
        maxsum=max(maxsum,root->val+ls+rs);
        return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxsum=INT_MIN;
        helper(root,maxsum);
        return maxsum;
    }
};