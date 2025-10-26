class Solution {
public:
    void helper(vector<int> nums,vector<int>& ans){
        if(nums.size()<1) return;
        int a=INT_MAX,b=INT_MAX,idx1=-1,idx2=-1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= a) {
            b = a;
            a = nums[i];
            idx2 = idx1;
            idx1 = i;
        } 
        else if (nums[i] <= b && nums[i] != a) {
            b = nums[i];
            idx2 = i;
        }
    }
    ans.push_back(b);
    ans.push_back(a);
    vector<int>nn;
    for(int i=0;i<nums.size();i++){
        if(i!=idx1 && i!=idx2) nn.push_back(nums[i]);
    }
    helper(nn,ans);
    return;
    }
    vector<int> numberGame(vector<int>& nums) {
        vector<int>ans;
        helper(nums,ans);
       return ans;
    }
};