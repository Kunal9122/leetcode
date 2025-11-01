class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>v(n*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int k=grid[i][j];
                v[k-1]+=1;
            }
        }
        vector<int>ans;
       for(int i = 0; i < n * n; i++){
            if(v[i] == 2) ans.push_back(i + 1);
        }
        for(int i = 0; i < n * n; i++){
            if(v[i] == 0) ans.push_back(i + 1);
        }
        return ans;
    }
};