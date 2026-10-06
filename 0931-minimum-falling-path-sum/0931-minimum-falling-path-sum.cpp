class Solution {
public:
    int helper(vector<vector<int>>& matrix,int r,int c, vector<vector<int>>& dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(r==n) return 0;
        if(c<0 || c==m) return INT_MAX;
       // if(matrix[r][c]==0) return INT_MAX;
        if(dp[r][c]!=INT_MAX) return dp[r][c];
        int s=0;
        dp[r][c]=matrix[r][c]+min({helper(matrix,r+1,c-1,dp),helper(matrix,r+1,c,dp),helper(matrix,r+1,c+1,dp)});
        return dp[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,helper(matrix,0,i,dp));
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};