class Solution {
public:
    vector<int> decrypt(vector<int>& code, int l) {
        int n=code.size();
        vector<int>ans(n,0);
        int s=0;
        if(l>0){
            for(int i=0;i<n;i++){
                int k=i+1;
                s=0;
                for(int j=0;j<l;j++){
                    if(k>=n) k=k%n;
                    s+=code[k];
                    k++;
                    
                }
                ans[i]=s;
            }
        }
            if(l<0){
                for(int i=0;i<n;i++){
                   int k=i-1;
                    s=0;
                    for(int j=0;j<(-1*l);j++){
                        if(k<0) k=n+k;
                        s+=code[k];
                        k--;
                    }
                    ans[i]=s;
                }
            }

        return ans;
    }
};