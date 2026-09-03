class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,maxLen=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) c++;
            else{
                maxLen=max(c,maxLen);
                c=0;
            }
        }
        maxLen=max(c,maxLen);
        return maxLen;
    }
};