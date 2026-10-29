class Solution {
public:
    int helper(vector<int>& prices, vector<vector<vector<int>>>& dp,int i,int buy,int cap){
        if(i==prices.size() || cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit=0;
        if(buy){
            int t=-prices[i]+helper(prices,dp,i+1,buy-1,cap);
            int l=helper(prices,dp,i+1,buy,cap);
            profit=max(t,l);
        }
        else{
            int s=prices[i]+helper(prices,dp,i+1,buy+1,cap-1);
            int ns=helper(prices,dp,i+1,buy,cap);
            profit=max(s,ns);
        }
        dp[i][buy][cap]=profit;
        return dp[i][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices,dp,0,1,2);
    }
};