class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>pg(n,-1);
        stack<int>st;
        st.push(prices[n-1]);
        for(int i=n-2;i>=0;i--){
            pg[i]=st.top();
            while(!st.empty() && prices[i]>st.top()){
                st.pop();
            }
            if(st.empty() || prices[i]>st.top()) st.push(prices[i]);
        }
        int maxProfit=0;
        for(int i=0;i<n;i++){
            maxProfit=max(maxProfit,pg[i]-prices[i]);
        }
        return maxProfit;
    }
};