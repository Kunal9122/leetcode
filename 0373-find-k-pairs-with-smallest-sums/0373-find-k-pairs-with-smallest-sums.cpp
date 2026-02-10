class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p,vector<p>,greater<p>>mp;
        for(int i=0;i<nums1.size() && i<k;i++){
                int s=nums1[i]+nums2[0];
                mp.push({s,{i,0}});
            }
        vector<vector<int>>ans;
        while(k>0 && mp.size()){
            int i=mp.top().second.first;
            int j=mp.top().second.second;
            ans.push_back({nums1[i],nums2[j]});
            mp.pop();
            k--;
            if(j+1<nums2.size()){
                mp.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};