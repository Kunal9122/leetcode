class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minE=prices[0];
        int maxPr=INT_MIN,k=0,i=0;
        while(i<n){
            minE=min(prices[i],minE);
            if(prices[i]-minE<maxPr){
                minE=prices[i];
                k+=maxPr;
                maxPr=INT_MIN;
            }
            else{maxPr=max(prices[i]-minE,maxPr);
            i++;
            }
        }
        k+=maxPr;
        return k;
    }
};