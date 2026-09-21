class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({i,j});
        while(q.size()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=-1;k<=1;k+=2){ // only 2 direction for row
                    int fr=r+k;
                    int fc=c;
                    if(fr>=0 && fr<n && fc >=0 && fc<m && grid[fr][fc]=='1' && !vis[fr][fc]){
                        q.push({fr,fc});
                        vis[fr][fc]=1;
                    }
                }
                for(int k=-1;k<=1;k+=2){ // only 2 direction for col
                    int fr=r;
                    int fc=c+k;
                    if(fr>=0 && fr<n && fc >=0 && fc<m && grid[fr][fc]=='1' && !vis[fr][fc]){
                        q.push({fr,fc});
                        vis[fr][fc]=1;
                    }
                }
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    c++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return c;
    }
};