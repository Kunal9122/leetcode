class Solution {
public:
    void helper(vector<int> nums,vector<double>& ans){
        if(nums.size()<1){
            return;
        }
        double minel=INT_MAX,maxel=INT_MIN;
        int idx1=-1,idx2=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(maxel<nums[i]){
                 maxel=nums[i];
                 idx1=i;
            }
           if(minel>nums[i]){
             minel=nums[i];
             idx2=i;
           } 
        }
        double c=(minel+maxel)/2;
        ans.push_back(c);
        vector<int>nv;
        for(int i=0;i<n;i++){
            if(i!=idx1&&idx2!=i) nv.push_back(nums[i]);
        }
        helper(nv,ans);
        return;

    }
    double minimumAverage(vector<int>& nums) {
        int n=nums.size();
        vector<double>ans;
        helper(nums,ans);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};