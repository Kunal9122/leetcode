class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        for(int i=0;i<s.size();i++){
            if(mp1.find(s[i])!=mp1.end()){
                char x=mp1[s[i]];
                if(x!=t[i]) return false;
            }
             else mp1[s[i]]=t[i];
             if(mp2.find(t[i])!=mp2.end()){
                char x=mp2[t[i]];
                if(x!=s[i]) return false;
            }
            else mp2[t[i]]=s[i];
        }
        return true;
    }
};