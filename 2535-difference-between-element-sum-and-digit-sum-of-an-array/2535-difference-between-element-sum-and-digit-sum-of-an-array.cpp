class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int digitSum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int k = nums[i];
            while(k){
                int j=k%10;
                digitSum+=j;
                k=k/10;
            }
        } 
        return sum-digitSum;
    }
};