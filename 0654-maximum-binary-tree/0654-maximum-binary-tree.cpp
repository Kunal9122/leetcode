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
    TreeNode* helper(vector<int> nums,int e,int st){
        if(st>e){
            return NULL;
        }
        int m=st,maxi=nums[st];
        for(int i=st;i<=e;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                m=i;
            }
        }
        TreeNode* nn=new TreeNode(nums[m]);
        nn->left=helper(nums,m-1,st);
        nn->right=helper(nums,e,m+1);
        return nn;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
       return helper(nums,n-1,0);
    }
};