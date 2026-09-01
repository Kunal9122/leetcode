class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                flag=true;
            }
        }
        if(flag==true){
            for(int i=n-2;i>=0;i--){
               if(nums[i+1]>nums[i]) return false;
            }
        }
        return true;
    }
};