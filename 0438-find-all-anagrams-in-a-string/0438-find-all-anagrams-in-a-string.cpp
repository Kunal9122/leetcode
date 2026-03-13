class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>st;
        unordered_map<char,int>stt;
        int n=p.size();
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            st[p[i]]++;
        }
        for(int i=0;i<n;i++){
            stt[s[i]]++;
        }
        if(stt==st) ans.push_back(0);
        int i=0,j=n;
        while(j<s.size()){
            stt[s[i]]--;
            if(stt[s[i]]==0) stt.erase(s[i]);
            stt[s[j]]++;
            if(stt==st) ans.push_back(i+1);
            i++;j++;
        }
        return ans;
    }
};