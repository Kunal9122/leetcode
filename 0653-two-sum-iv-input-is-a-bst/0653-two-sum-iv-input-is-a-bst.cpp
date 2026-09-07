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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        int c=0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode* n=q.front();
            q.pop();
            int v=n->val;
            if(mp.find(k-v)!=mp.end()){
                c++;
                return true;
            }
            mp[v]++;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        return false;
    }
};