class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),len=0,minLen=INT_MAX;
        int sum=0,i=0,j=0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                len=j-i+1;
                minLen=min(len,minLen);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX) return 0;
        return minLen;
    }
};