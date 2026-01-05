class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       priority_queue<long long,vector<long long>,greater<long long>>pq;
       for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
       } 
       int c=0;
       while(pq.top()<k){
        long long x=pq.top();
        pq.pop();
        long long y=pq.top();
        pq.pop();
        long long p=x*2+y;
        pq.push(p);
        c+=1;
       }
       return c;
    }
};