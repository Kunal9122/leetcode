class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int len=0,maxLen=INT_MIN;
        int i=0,j=0;
        bool flag=true;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flag==true){
                    flag=false;
                    j++;
                }
                else{
                    len=j-i;
                    maxLen=max(maxLen,len);
                    while(nums[i]==1) i++;
                    i++;
                    flag=true;
                }
            }
        } 
        len=j-i;
        maxLen=max(maxLen,len);
        return maxLen-1;   
    }
};