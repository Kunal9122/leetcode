class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1,k,j;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            for(j=0,k=n-1;j<=k;j++,k--){
                swap(nums[j],nums[k]);
            }
             return;
        }
       for(j=idx+1,k=n-1;j<=k;j++,k--){
        swap(nums[j],nums[k]);
       }
       j=-1;
       for(int i=idx+1;i<n;i++){
        if(nums[i]>nums[idx]){
            j=i;
            break;
        }
       }
       swap(nums[idx],nums[j]);
        return;
    }
};