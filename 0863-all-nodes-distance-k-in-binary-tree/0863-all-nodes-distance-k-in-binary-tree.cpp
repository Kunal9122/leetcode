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
    void track(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp){
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            TreeNode* n=q.front();
            q.pop();
           if(n->left){
            mp[n->left]=n;
            q.push(n->left);
            }

            if(n->right){
                mp[n->right]=n;
                q.push(n->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        track(root,mp);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int c=0;
        while(q.size()){
            
            
            if(c==k) break;
            c++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left && !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right && !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(mp[cur] && !vis[mp[cur]]){
                    q.push(mp[cur]);
                    vis[mp[cur]]=true;
                }
            }
        }
        vector<int>ans;
        while(q.size()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};