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
    typedef pair<TreeNode*,pair<int,int>>p;
    typedef pair<pair<int,int>,int>pi;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        if(!root) return ans;
        queue<p>q;
        queue<p>q1;
        q.push({root,{0,0}});
        while(q.size()){
            // q1.push(q.front());
            TreeNode* node=q.front().first;
            int lev=q.front().second.first;
            int ver=q.front().second.second;
            pq.push({{ver,lev},node->val});
            if(node->left) q.push({node->left,{lev+1,ver-1}});
            if(node->right) q.push({node->right,{lev+1,ver+1}});
            q.pop();
        }
        vector<int>v;
        int prev=pq.top().first.first;
        while(pq.size()){
            int val=pq.top().second;
            int cur=pq.top().first.first;
            if(cur!=prev){
                ans.push_back(v);
                v.clear();
            }
            prev=cur;
            v.push_back(val);
            pq.pop();
        }
        ans.push_back(v);
        return ans;
    }
};