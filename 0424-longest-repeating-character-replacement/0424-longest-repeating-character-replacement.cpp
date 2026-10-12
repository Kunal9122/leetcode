class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0,maxLen=0,maxfreq=0;
        vector<int>mp(26,0);
        
        while(j<n){
            int idx=s[j]-'A';
            mp[idx]++;
            maxfreq=max(maxfreq,mp[idx]);
            if(j-i+1-maxfreq<=k) maxLen=max(maxLen,j-i+1);
            else{
            while(i<j && j-i+1-maxfreq > k){
                int l=s[i]-'A';
                mp[l]--;
                maxfreq=0;
                for(int m=0;m<26;m++){
                    maxfreq=max(maxfreq,mp[m]);
                }
                i++;
            }
            }
            j++;
        }
        return maxLen;
    }
};