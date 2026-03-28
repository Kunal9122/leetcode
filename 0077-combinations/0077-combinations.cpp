class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>v ,int k,int n,int j){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=j;i<=n;i++){
            v.push_back(i);
            helper(ans,v,k,n,i+1);
            v.pop_back();
        }
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>>ans;
         vector<int>v;
         int j=1;
         helper(ans,v,k,n,j);
        return ans;
    }
};