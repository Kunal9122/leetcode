class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>pre(n+1);
        vector<int>suff(n+1);
        int N=0;
        int Y=0;
        for(int i=0;i<n;i++){
            pre[i]=N;
            if(customers[i]=='N') N++;
        }
        pre[n]=N;
        suff[n]=Y;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y') Y++;
            suff[i]=Y;
        }
        for(int i=0;i<=n;i++){
            pre[i]=pre[i]+suff[i];
        }
        int minEl=pre[0];
        for(int i=0;i<=n;i++){
            if(pre[i]<=minEl){
                minEl=pre[i];
            }
        }
        int idx=-1;
        for(int i=0;i<=n;i++){
            if(pre[i]==minEl){
                idx=i;
                break;
            }
        }
        return idx;
    }
};