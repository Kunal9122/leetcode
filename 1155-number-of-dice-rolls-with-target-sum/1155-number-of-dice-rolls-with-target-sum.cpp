class Solution {
public:
    int helper(int n,int k,int target, vector<vector<int>>& dp){
        if(n==0 && target==0){
            return 1;
        }
        if(n==0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int sum=0;
        for(int i=1;i<=k;i++){
            if(target-i<0) continue;
            sum+=helper(n-1,k,target-i,dp);
            sum%=1000000007;
        }
        dp[n][target]=sum;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans=helper(n,k,target,dp);
        return ans;
    }
};