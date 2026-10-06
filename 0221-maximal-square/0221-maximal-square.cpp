class Solution {
public:
    int helper(vector<vector<char>>& matrix,int r,int c,vector<vector<int>>& dp){
       int n=matrix.size();
       int m=matrix[0].size();
       if(r>=n || c>=m) return 0;

       if(matrix[r][c]=='0') return 0;
        if(dp[r][c]!=-1) return dp[r][c];

       return dp[r][c]=1+min({helper(matrix,r+1,c,dp),helper(matrix,r,c+1,dp),helper(matrix,r+1,c+1,dp)});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int ans=0;
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[0].size();j++){
               ans=max(ans,helper(matrix,i,j,dp));
            }
        }
        return ans*ans;
    }
};