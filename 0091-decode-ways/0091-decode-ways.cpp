class Solution {
public:
    int helper(int i,string s,vector<int>& dp){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int a=helper(i+1,s,dp);
        int b=0;
        if(i+1<s.size()){
            int n=(s[i]-'0')*10+(s[i+1]-'0');
            if(n>=10 && n<=26){
                b=helper(i+2,s,dp);
            }
        }
        dp[i]=a+b;
        return dp[i];
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return helper(0,s,dp);
    }
};