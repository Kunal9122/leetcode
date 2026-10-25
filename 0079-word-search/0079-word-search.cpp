class Solution {
public:
    bool helper(vector<vector<char>>& board, string word,string temp,int i,int j,vector<vector<bool>>& vis){
        int n=board.size();
        int m=board[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        if(vis[i][j]==true) return false;
        temp+=board[i][j];
        if(temp.size()>word.size()||temp!=word.substr(0,temp.size())) return false;
        if(temp==word) return true;
        
        vis[i][j]=true;
        if(helper(board,word,temp,i+1,j,vis)) return true;
        if(helper(board,word,temp,i-1,j,vis)) return true;
        if(helper(board,word,temp,i,j+1,vis)) return true;
        if(helper(board,word,temp,i,j-1,vis)) return true;
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        string temp="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>>vis(n,vector<bool>(m,0));
                if(helper(board,word,temp,i,j,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};