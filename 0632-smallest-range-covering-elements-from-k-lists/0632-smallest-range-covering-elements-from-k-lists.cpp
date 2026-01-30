class Solution {
public:
    typedef pair<int,pair<int,int>>pip;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(nums[i][0],mx);
            pq.push({nums[i][0],{i,0}});
        }
        int mn=pq.top().first;
        int s=mn,e=mx;
        while(true){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(c==nums[r].size()-1) break;
            pq.push({nums[r][c+1],{r,c+1}});
            mx=max(mx,nums[r][c+1]);
            mn=pq.top().first;
            if(mx-mn<e-s){
                s=mn;
                e=mx;
            }
        }
        return {s,e};
    }
};