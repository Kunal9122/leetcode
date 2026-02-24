class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxLen=0,maxFreq=0;
        vector<int>v(26,0);
        while(r<s.size()){
            int d=s[r]-'A';
            v[d]++;
            maxFreq=max(maxFreq,v[d]);
            while((r-l+1)-maxFreq>k){
                int m=s[l]-'A';
                v[m]--;
                maxFreq=0;
                for(int i=0;i<26;i++){
                    maxFreq=max(maxFreq,v[i]);
                }
                l++;
            }
            if((r-l+1)-maxFreq<=k){
                maxLen=max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};