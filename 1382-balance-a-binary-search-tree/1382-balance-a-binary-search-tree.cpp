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
    void store(TreeNode *root,vector<int>& v){
        if(!root) return;
        store(root->left,v);
        v.push_back(root->val);
        store(root->right,v);
        return;
    }
     TreeNode* merge(vector<int> v,int s,int m,int e){
        if(s>e) return NULL;
        TreeNode *nn=new TreeNode(v[m]);
        int mi=(s+m-1)/2;
        nn->left=merge(v,s,mi,m-1);
        int ni=(m+1+e)/2;
        nn->right=merge(v,m+1,ni,e);
        return nn;
     }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        store(root,v);
        int n=v.size();
        int m=(0+n)/2;
        TreeNode* head=merge(v,0,m,n-1);
        return head;
    }
};