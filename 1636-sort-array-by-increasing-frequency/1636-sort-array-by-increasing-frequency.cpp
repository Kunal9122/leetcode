class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int ele:nums){
            mp[ele]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto x:mp){
            int ele=-x.first,fre=x.second;
            pair<int,int>p={fre,ele};
            pq.push(p);
        }
        vector<int>ans;
        while(pq.size()){
            int ele=-pq.top().second;
            int freq=pq.top().first;
            for(int i=0;i<freq;i++){
                ans.push_back(ele);
            }
            pq.pop();
        }
        return ans;
    }
};