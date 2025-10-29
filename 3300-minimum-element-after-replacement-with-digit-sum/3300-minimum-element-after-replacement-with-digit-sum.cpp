class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i];
            int s=0;
            while(a){
                int r=a%10;
                s+=r;
                a=a/10;
            }
            nums[i]=s;
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};