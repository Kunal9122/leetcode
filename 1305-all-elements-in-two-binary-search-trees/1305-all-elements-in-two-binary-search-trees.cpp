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
    void helper(TreeNode* root,vector<int>& v1){
        if(!root) return;
        helper(root->left,v1);
        v1.push_back(root->val);
        helper(root->right,v1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> v1;
        vector<int> v2;
        helper(root1,v1);
        helper(root2,v1);
        sort(v1.begin(),v1.end());
        return v1;
    }
};