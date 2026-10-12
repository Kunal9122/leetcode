class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size(); 
        int s=0,mini=INT_MAX;
        int i=0,j=0;
        while(j<n){
            s+=nums[j];
            while(i<=j && s>=target){
                mini=min(mini,j-i+1);
                s-=nums[i];
                i++;
            }
            j++;
        }
        if(mini==INT_MAX) return 0;
        return mini;
    }
};