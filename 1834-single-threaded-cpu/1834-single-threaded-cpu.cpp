class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> getOrder(vector<vector<int>>& tasks) {
         vector<vector<int>> v;
         int n=tasks.size();
        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(v.begin(), v.end());
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        long long curr=0.,idx=0;
         vector<int>ans;
        while(idx<n || pq.size()){
            if(pq.empty() && curr<v[idx][0]) curr=v[idx][0];
            while( idx<n && v[idx][0]<=curr){
                pi p={v[idx][1],v[idx][2]};
                pq.push(p);
                idx++;
            }
            pi p=pq.top();
            curr+=p.first;
           ans.push_back(p.second);
           pq.pop();
        }
        return ans;
    }
};