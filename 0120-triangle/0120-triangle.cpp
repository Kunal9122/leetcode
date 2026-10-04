class Solution {
public:
    int helper(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>& dp){
        int n=triangle.size();
        if(row==n) return 0;
        if(dp[row][col]!=INT_MIN) return dp[row][col];
        dp[row][col]=triangle[row][col]+min(helper(triangle,row+1,col,dp),helper(triangle,row+1,col+1,dp));
        return dp[row][col];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
        return helper(triangle,0,0,dp);

    }
};