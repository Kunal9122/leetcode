class Solution {
public:
    int rev(int n){
        int r=0;
        while(n){
            int j=n%10;
            r=r*10+j;
            n=n/10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        unordered_map<int,int>mp;
        int c=0;
        for(int x : nums){
             if(mp.find(x)!=mp.end()){
              c=c% 1000000007;
                c+=mp[x];
                mp[x]++;
            }
            else
            mp[x]++;
        }
        return c%1000000007;
    }
};