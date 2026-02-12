class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=1;
        }
        for(int i=0;i<t.size();i++){
            char ch=t[i];
            if(mp.find(ch)!=mp.end()){
                mp[ch]-=1;
                if(mp[ch]==0) mp.erase(ch);
            }
            else return false;
        }
        if(mp.size()) return false;
        return true;
    }
};