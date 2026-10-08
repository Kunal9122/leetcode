class Solution {
public:
    int helper(vector<int>& nums,int i,int previ,vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n) return 0;
        if(dp[i][previ+1]!=-1) return dp[i][previ+1];
        int s=0+helper(nums,i+1,previ,dp);
        if(previ==-1 || nums[i]>nums[previ]) s=max(s,1+helper(nums,i+1,i,dp));
        dp[i][previ+1]=s;
        return dp[i][previ+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(nums,0,-1,dp);
    }
};