class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int a=n-1;
        int b=n-2;
        int c=0;
        int m=0;
        while(b>c){
            m+=piles[b];
            b-=2;
            c++;
        }
        return m;
    }
};