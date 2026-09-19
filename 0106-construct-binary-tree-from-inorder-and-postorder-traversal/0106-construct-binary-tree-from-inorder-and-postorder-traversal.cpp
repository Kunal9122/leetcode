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
    TreeNode* build(vector<int>& inorder,int il,int ih, vector<int>& postorder,int pl,int ph, map<int,int>& mp){
        if(il>ih || pl>ph) return NULL;
        TreeNode* root=new TreeNode(postorder[ph]);
        int node=mp[root->val];
        int act=node-il;
        root->left=build(inorder,il,node-1,postorder,pl,pl+act-1,mp);
        root->right=build(inorder,node+1,ih,postorder,act+pl,ph-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        return build(inorder,0,n-1,postorder,0,n-1,mp);
    }
};