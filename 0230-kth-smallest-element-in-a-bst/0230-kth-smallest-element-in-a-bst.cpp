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
    int c=0,ans=INT_MAX;
    void helper(TreeNode* root,int &k){
        if(!root) return;
        helper(root->left,k);
        if(k==1){
            ans=min(ans,root->val);
            return;
        }
        k=k-1;
        helper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};