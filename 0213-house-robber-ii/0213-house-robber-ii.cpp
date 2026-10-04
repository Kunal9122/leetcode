class Solution {
public:
  int helper(vector<int>& nums,int i,vector<int>& dp,int n){
        if(i==n) return nums[i];
        if(i==n-1) return max(nums[i],nums[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+helper(nums,i+2,dp,n),0+helper(nums,i+1,dp,n));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,-1);
        int f=helper(nums,0,dp,n-2);
        dp.assign(n, -1);
        int l=helper(nums,1,dp,n-1);
        return max(f,l);
    }
};