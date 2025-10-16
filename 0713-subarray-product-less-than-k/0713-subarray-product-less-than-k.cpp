class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       if(k<=1) return 0;
        int n=nums.size();
        int i=0,j=0,c=0,product=1;
        while(j<n){
            product*=nums[j];
            while(product>=k){
                c+=(j-i);
                product/=nums[i];
                i++; 
            }
             j++;
        }
           while(i<n){
                c+=(j-i);
                product/=nums[i];
                i++;
            }
        return c;
    }
};