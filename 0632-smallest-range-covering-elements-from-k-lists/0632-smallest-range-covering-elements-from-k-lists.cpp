class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<p,vector<p>,greater<p>>pq;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            mx=max(mx,nums[i][0]);
        }
        int s=pq.top().first;
        int e=mx;
        int mn=s;
        while(1){
            int num=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(nums[row].size() <= col+1) break;
            pq.push({nums[row][col+1],{row,col+1}});
            mx=max(mx,nums[row][col+1]);
            mn=pq.top().first;
            if(mx-mn < e-s){
                s=mn;
                e=mx;
            }
        }
        return {s,e};
    }
};