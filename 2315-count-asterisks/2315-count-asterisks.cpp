class Solution {
public:
    int countAsterisks(string s) {
        int n=s.size();
        int c=0;
        int bar=0;
        for(int i=0;i<n;i++){
              if(s[i]=='|') bar++;
            if(bar%2==1) continue;
          
            if(s[i]=='*') c++;
        }
        return  c;
    }
};