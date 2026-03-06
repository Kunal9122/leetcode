class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix(n);
        vector<long long>suffix(n);
        suffix[n-1]=0;
        prefix[0]=0;
        vector<int>ans(n,-1);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i+1];
        }
        int i=k;
        while(i<n-k){
            int l=i-k;
            int r=i+k;
            long long s=prefix[i]+suffix[i]-prefix[l]-suffix[r]+nums[i];
            ans[i]=s/(k*2+1);
            i++;
        }
        return ans;
    }
};