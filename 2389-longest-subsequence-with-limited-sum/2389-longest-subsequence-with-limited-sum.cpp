class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans(m);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
       
        for(int i=0;i<m;i++){
            int l=0;
            int h=n-1;
            int len=0;
            while(l<=h){
                int m=(l+h)/2;
                if(nums[m]>queries[i]) h=m-1;
                else{
                    len=m+1;
                    l=m+1;
                }
            }
            ans[i]=len;
        }
        return ans;
    }
};