class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int c1=0,c2=0;
        int n=nums.size();
        int mx=nums[0];
        if(n==k){
            for(int i=0;i<n;i++) mx=max(nums[i],mx);
            return mx;
        }
        if(k==1){
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++) mp[nums[i]]++;
            int mx=-1;
            while(mp.size()){
                auto x=mp.begin();
                if(x->second==1){
                    mx=max(mx,x->first);
                }
                mp.erase(x);
            }
            return mx;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[0]) c1++;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[nums.size()-1]) c2++;
        }
        if(c1 > 0 && c2>0) return -1;
        if(c1<c2){
            return nums[0];
        }
        if(c2<c1) return nums[n-1];
        else return max(nums[0],nums[n-1]);
    }
};