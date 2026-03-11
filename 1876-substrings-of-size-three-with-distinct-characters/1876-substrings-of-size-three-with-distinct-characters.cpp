class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3) return 0;
        int ans=0;
        unordered_map<char,int>mp;
        int i=0,j=3,n=s.size();
        for(i=0;i<3;i++){
           mp[s[i]]++;
        }
        i=0;
        if(mp.size()==3) ans++;
       
        while(j<n){
          mp[s[j]]++;
          mp[s[i]]--;
          if(mp[s[i]]==0) mp.erase(s[i]);
          if(mp.size()==3) ans++;
          i++;j++;
        }
        return ans;
    }
};