class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        for(int i=1;i<n;i++){
            nums[i]=max(nums[i],nums[i-1]-1);
            if(nums[i]==0 && i<n-1) return false;
        }
        return true;
    }
};