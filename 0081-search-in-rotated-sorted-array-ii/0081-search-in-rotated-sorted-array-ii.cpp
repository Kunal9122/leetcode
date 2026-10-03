class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<2 && nums[0]!=target) return false;
        if(n<2 && nums[0]==target) return true;
        int s=0,e=n-1;
        int p=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]<nums[i]){
                p=i+1;
                break;
            }
        }
        if(p!=-1)
        e=p-1;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target) return true;
            else if(nums[m]>target){
                e=m-1;
            }
            else {
                s=m+1;
            }
        }
        if(p!=-1)
        s=p;
        e=n-1;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target) return true;
            else if(nums[m]>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return false;
    }
};