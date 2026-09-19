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
    TreeNode* helper(vector<int> preorder, vector<int> inorder,int& idx){
        int n=inorder.size();
        if(n==0) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        vector<int>inL;
        for(int i=0;i<n;i++){
            if(inorder[i]==root->val) break;
            inL.push_back(inorder[i]);
        }
        TreeNode* leftT=NULL;
        leftT=helper(preorder,inL,idx);
        root->left=leftT;
        vector<int>inR;
        for(int i=n-1;i>=0;i--){
            if(inorder[i]==root->val) break;
            inR.push_back(inorder[i]);
        }
        reverse(inR.begin(),inR.end());
        TreeNode* rightT=NULL;
        rightT=helper(preorder,inR,idx);
        root->right=rightT;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return helper(preorder,inorder,idx);
    }
};