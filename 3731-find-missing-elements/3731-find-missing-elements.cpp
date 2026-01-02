class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
         sort(nums.begin(),nums.end());
        vector<int>ans;
       
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
                int x=nums[i-1]+1;
                while (x < nums[i]) {   
                ans.push_back(x);
                x++;
            }
            }
        }
        return ans;
    }
};