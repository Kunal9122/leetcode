class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            int rev=0;
            while(nums[i]){
                int j=nums[i]%10;
                rev=rev*10+j;
                nums[i]=nums[i]/10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};