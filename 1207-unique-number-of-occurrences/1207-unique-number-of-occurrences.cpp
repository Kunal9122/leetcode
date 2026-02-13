class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]+=1;
        }
        int n=mp.size();
        unordered_set<int>s;
        for(int i=0;i<arr.size();i++){
            if(mp.size()==0) break;
            auto a=mp.begin();
            s.insert(a->second);
            mp.erase(a);
        }
        if(n==s.size()) return true;
        else return false;
    }
};