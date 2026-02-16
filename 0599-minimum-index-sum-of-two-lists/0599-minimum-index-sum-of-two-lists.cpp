class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp;
        vector<string>ans;
        for(int i=0;i<list1.size();i++){
            mp[list1[i]]=i;
        }
         int c=INT_MAX;
        for(int i=0;i<list2.size();i++){
            int mini=INT_MAX;
            if(mp.find(list2[i])!=mp.end()){
                int j=mp[list2[i]];
                int mini=min(i+j,mini);
                c=min(mini,c);
            }
        }
            for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end()){
                int j=mp[list2[i]];
               if(i+j==c) ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};