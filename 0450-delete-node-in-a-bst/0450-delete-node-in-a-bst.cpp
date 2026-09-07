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
    TreeNode* deleteN(TreeNode* temp){
        if(!temp->left) return temp->right;
        if(!temp->right) return temp->left;
        TreeNode* rightNode=temp->right;
        TreeNode* leftG=greater(temp->left);
        leftG->right=rightNode;
        return temp->left;
    }
    TreeNode* greater(TreeNode* root){
        if(root->right==NULL) return root;
        return greater(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key) return deleteN(root);
        TreeNode* temp=root;
        while(temp){
            if(temp->val>key){
                if(temp->left && temp->left->val==key){
                    temp->left=deleteN(temp->left);
                    break;
                }
                else temp=temp->left;
            }
            else{
                if(temp->right && temp->right->val==key){
                   temp->right= deleteN(temp->right);
                    break;
                }
                else temp=temp->right;
            }

        }
        return root;
    }
};