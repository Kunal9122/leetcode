/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        queue<TreeNode*>q;
        q.push(root);
        string ans="";
        while(q.size()){
            TreeNode* n=q.front();
            q.pop();
            if(n==NULL) ans.append("#,");
            else ans.append(to_string(n->val)+',');
            if(n!=NULL){
                q.push(n->left);
                q.push(n->right);
            }
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        if(str == "#") return NULL;
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            TreeNode* n=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") n->left=NULL;
            else{
                TreeNode* leftT=new TreeNode(stoi(str));
                n->left=leftT;
                q.push(leftT);
            }
            getline(s,str,',');
            if(str=="#") n->right=NULL;
            else{
                TreeNode* rightN=new TreeNode(stoi(str));
                n->right=rightN;
                q.push(rightN);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));