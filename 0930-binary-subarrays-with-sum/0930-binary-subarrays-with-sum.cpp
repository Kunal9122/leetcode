class Solution {
public:
    int atMost(vector<int>& nums, int k){
         int ans=0,s=0,i=0,j=0;
         if(k<0) return 0;
        while(j<nums.size()){
            s+=nums[j];
            while(s>k){
                s-=nums[i];
                i++;
            }
            ans=ans+j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums,goal)-atMost(nums,goal-1);
    }
};