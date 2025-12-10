class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
       deque<int> dq;
       int i=0;
       while(i<n){
        while(!dq.empty()>0&&nums[dq.back()]<nums[i])  dq.pop_back();
        dq.push_back(i);
        int j=i+1-k;
        while(dq.front()<j) dq.pop_front();
        if(i>=k-1) ans.push_back(nums[dq.front()]);
        i++;
       } 
       return ans;
    }
};