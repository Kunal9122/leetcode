class Solution {
public:
    bool safe(vector<string>& s,int c,int r,int n){
            for(int j = 0; j < c; j++) {
            if(s[r][j] == 'Q') return false;
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(s[i][j]=='Q') return false;
        }
        for(int i=r+1,j=c-1;i<n && j>=0;i++,j--){
            if(s[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(vector<vector<string>>& ans,int n,int c,vector<string>& s){
        if(c==n){
            ans.push_back(s);
            return;
        }
        for(int r=0;r<n;r++){
            if(safe(s,c,r,n)){
                s[r][c]='Q';
                helper(ans,n,c+1,s);
                s[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<string>s(n,string(n,'.'));
       vector<vector<string>>ans;
       helper(ans,n,0,s);
       return ans; 
    }
};