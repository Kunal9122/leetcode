class Solution {
public:
    int helper(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
        int n=s1.size();
        int m=s2.size();
       if(i == n)
            return m - j;
        if(j == m)
            return n - i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return helper(s1,s2,i+1,j+1,dp);
        }
        int in=INT_MAX;
        in= min(in,1+(helper(s1,s2,i,j+1,dp)));
        int de=INT_MAX;
        de=min(de,1+helper(s1,s2,i+1,j,dp));
        int r=INT_MAX;
        r=min(r,1+helper(s1,s2,i+1,j+1,dp));
        return dp[i][j]=min({in,de,r});

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(word1,word2,0,0,dp);
    }
};