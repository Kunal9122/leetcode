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
   
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
       queue<pair<TreeNode*,int>>q;
       q.push({root,0});
       int ans=0;
       while(q.size()){
        int mini=q.front().second;
        int n=q.size();
        int first,last;
        for(int i=0;i<n;i++){
            TreeNode* node=q.front().first;
            int id=q.front().second-mini;
            if(i==0) first=id;
            if(i==n-1) last=id;
            q.pop();
            if(node->left) q.push({node->left,2LL*id+1});
            if(node->right) q.push({node->right,(2LL*id+2)});
        }
        ans=max(ans,last-first+1);
       } 
       return ans;
    }
};