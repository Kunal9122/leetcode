class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            int s=nums[i];
            int k=0;
            while(s>0){
                int j=s%10;
                k+=j;
                s/=10;
            }
            if(k==i){
                idx=i;
                break;
            }
        }
        return idx;
    }
};