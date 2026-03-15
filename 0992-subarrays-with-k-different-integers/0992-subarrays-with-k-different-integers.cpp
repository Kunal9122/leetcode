class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0,count=0;
        if(k<=0) return 0;
        while(j<n){
            mp[nums[j]]++;
            while(i<j && mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};