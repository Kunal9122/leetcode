class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0,maxLen=0;
        unordered_map<char,int>mp;
        while(j<n){
            if(mp.find(s[j])==mp.end()){
                maxLen=max(maxLen,j-i+1);
                mp[s[j]]++;
                j++;
            }
            else{
                while(mp.find(s[j])!=mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            }

        }
        return maxLen;
    }
};