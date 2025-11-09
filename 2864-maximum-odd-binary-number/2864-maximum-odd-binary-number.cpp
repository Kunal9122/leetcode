class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') c++;
        }
        string ans="";
        for(int i=0;i<s.size()-1;i++){
            if(c>1){
                ans+='1';
                c--;
            } 
            else ans+='0';
        }
        ans+='1';
        return ans;
    }
};