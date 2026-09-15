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
    int level(TreeNode* root){
        if(!root) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void levelOrder(TreeNode* root,int a,int b,int& curr){
        if(!root) return;
        if(a==b) curr=root->val;
        levelOrder(root->left,a,b+1,curr);
        levelOrder(root->right,a,b+1,curr);
        return;
    }
    void helper(TreeNode* root,vector<int>& ans,int n){
        int curr=0;
        for(int i=0;i<n;i++){
            levelOrder(root,i,0,curr);
            ans.push_back(curr);
            curr=0;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        int n=level(root);
        vector<int>ans;
        helper(root,ans,n);
        return ans;
    }
};