class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]-mini);
            mini=min(nums[i],mini);
        }
        return ans;
    }
};