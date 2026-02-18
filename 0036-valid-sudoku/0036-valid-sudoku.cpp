class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>>row;
        unordered_map<int,unordered_set<char>>col;
        unordered_map<int,unordered_set<char>>b;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int box = (i/3)*3 + (j/3);
                if(board[i][j]=='.') continue;
                char ch=board[i][j];
                if(row[i].find(ch)!=row[i].end()||
                    col[j].find(ch)!=col[j].end()||
                    b[box].find(ch)!=b[box].end()
                ) return false;
                row[i].insert(ch);
                col[j].insert(ch);
                b[box].insert(ch);
            }
        }
        return true;
    }
};