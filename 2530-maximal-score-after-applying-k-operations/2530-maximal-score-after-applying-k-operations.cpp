class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            double x=pq.top();
            ans+=x;
            x=ceil(x/3);
            pq.push(x);
            k--;
            pq.pop();
        }
        return ans;
    }
};