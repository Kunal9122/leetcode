class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>nsi(n,0);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[i]>=prices[j]){
                    nsi[i]=prices[j];
                    break;
                }  
            }
            ans[i]=prices[i]-nsi[i];
        }
        return ans;
    }
};