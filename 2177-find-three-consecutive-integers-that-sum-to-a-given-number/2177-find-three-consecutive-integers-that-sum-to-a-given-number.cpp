class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>ans(3);
        long long n=num/3;
        ans[0]=n-1;
        ans[1]=n;
        ans[2]=n+1;
        long long c=0;
        for(int i=0;i<3;i++){
            c+=ans[i];
        }
        if(c==num) return ans;
        else return {};
    }
};