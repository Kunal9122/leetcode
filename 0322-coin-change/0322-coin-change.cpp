class Solution {
public:
   int f(vector<int>& coins, int amount,vector<int>& dp){
        if(amount==0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int r=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ar=f(coins,amount-coins[i],dp);
            if(ar!=INT_MAX) r=min(r,1+ar);
        }
        dp[amount]=r;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans= f(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};