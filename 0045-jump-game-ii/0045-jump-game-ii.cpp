class Solution {
public:
    int helper(vector<int>& nums,vector<int>& dp,int idx){
        int n=nums.size();
        if(idx >= n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int k=nums[idx];
        int m=INT_MAX;
        for(int i=idx+1;i<=idx+k && i<n;i++){
            int r=helper(nums,dp,i);
             if(r != INT_MAX)
                m = min(m, 1 + r);
        } 
        dp[idx]=m;
        return dp[idx];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(nums,dp,0);
    }
};