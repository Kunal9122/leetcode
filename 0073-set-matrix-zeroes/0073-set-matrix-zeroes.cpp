class Solution {
public:
    typedef pair<int,int>p;
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        set<p>id;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    id.insert({i,j});
                }
            }
        }
        while(id.size()>0){
            int r=id.begin()->first;
            int c=id.begin()->second;
            id.erase(id.begin());
            for(int i=0;i<m;i++){
                matrix[r][i]=0;
            }
            for(int i=0;i<n;i++){
                matrix[i][c]=0;
            }
        }
        return;
    }
};