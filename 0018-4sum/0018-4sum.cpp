class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(nums.size()<4) return ans;
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=nums.size()-1;
                int s=nums[i]+nums[j];
                vector<int>v;
                while(k<l){
                    long long sum = (long long)s + nums[k] + nums[l];
                    if(sum==target){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[l]);
                        ans.push_back(v);
                        v.clear();
                        k++;l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                   else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};