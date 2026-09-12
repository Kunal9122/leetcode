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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(st1.size()){
            TreeNode* n=st1.top();
            st1.pop();
            st2.push(n);
            if(n->left) st1.push(n->left);
            if(n->right) st1.push(n->right);
            
        }
        while(st2.size()){
            TreeNode* n=st2.top();
            ans.push_back(n->val);
            st2.pop();
        }
        return ans;
    }
};