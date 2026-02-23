class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3,-1);
        int c=0;
        for(int i=0;i<s.size();i++){
            int k=s[i]-'a';
            v[k]=i;
            if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1){
                int r=min(v[0],v[1]);
                c+=1+min(r,v[2]);
            }
        }
        return c;
    }
};