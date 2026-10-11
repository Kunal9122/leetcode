class Solution {
public:
    bool safe(vector<string>& s,int r,int c,int n){
        for(int i=0;i<c;i++){
            if(s[r][i]=='Q') return false;
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(s[i][j]=='Q') return false;
        }
        for(int i=r+1,j=c-1;i<n && j>=0;i++,j--){
            if(s[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(vector<string>& s,int n,int c,int& ans){
        if(c==n){
            ans+=1;
            return;
        }
        for(int r=0;r<n;r++){
            if(safe(s,r,c,n)){
                s[r][c]='Q';
                helper(s,n,c+1,ans);
                s[r][c]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>s(n,string(n,'.'));
        int ans=0;
        helper(s,n,0,ans);
        return ans;
    }
};