class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minLen=INT_MAX;
        int i=0,j=0;
        int s=0;
        while(j<n){
            s+=nums[j];
            while(s>=target){
                minLen=min(minLen,j-i+1);
                s-=nums[i];
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX) return 0;
        return minLen;
    }
};