class Solution {
public:
    int helper(vector<int>& nums,int t,int i,map<pair<int,int>, int>& dp){
        int n=nums.size();
        if(i==n && t==0) return 1;
        if(i==n) return 0;
        if(dp.find({i,t})!=dp.end()) return dp[{i,t}];
        dp[{i,t}]=helper(nums,t-nums[i],i+1,dp)+helper(nums,t+nums[i],i+1,dp);
        return dp[{i,t}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pair<int,int>, int> dp;
        return helper(nums,target,0,dp);
    }
};