class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            mp[key].push_back(strs[i]);
        }
        while(mp.size()){
            auto it=mp.begin();
            vector<string>v=it->second;
            ans.push_back(v);
            mp.erase(it);
        }
        return ans;
    }
};