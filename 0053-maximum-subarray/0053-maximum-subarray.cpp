class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int s=0,maxisum=INT_MIN;
        while(j<n){
            s+=nums[j];
            maxisum=max(maxisum,s);
            if(s<0){
                s=0;
            }
            j++;
        }
        //if(maxisum<0) return -1;
        return maxisum;
    }
};