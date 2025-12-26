class Solution {
public:
    typedef pair<int,vector<int>>piv;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<piv>pq;
        for(auto v: arr){
            int x=v[0],y=v[1];
            int d=(x*x)+(y*y);
            piv p = {d,v};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};