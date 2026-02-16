class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>p;
        for(int i=0;i<s.size();i++){
            p[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            int c=p[s[i]];
            if(c==1) return i;
        }  
        return -1;
    }
};