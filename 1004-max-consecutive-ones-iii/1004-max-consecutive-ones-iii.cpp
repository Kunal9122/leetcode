class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),flip=0;
        int maxLen=INT_MIN,len=0,i=0,j=0;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flip<k){
                    flip++;
                    j++;
                }
                else{
                    len=j-i;
                    maxLen=max(maxLen,len);
                    while(nums[i]==1) i++;
                    i++;
                    flip--;
                }
            }
        }
        len=j-i;
        maxLen=max(maxLen,len);
        return maxLen;         
    }
};