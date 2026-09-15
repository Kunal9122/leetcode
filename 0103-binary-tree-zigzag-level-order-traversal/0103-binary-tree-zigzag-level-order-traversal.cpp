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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root) return ans;
        q.push(root);
        bool flag=true;
        while(q.size()){
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                    v.push_back(node->val);
            }
            if(!flag) {
                reverse(v.begin(),v.end());
                flag=true;
            }
            else{
                flag=false;
            }
            ans.push_back(v);
        }
        return ans;
    }
};